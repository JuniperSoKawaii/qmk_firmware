/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#include "mf_wordwrap.h"

#ifndef MF_NO_COMPILE

/* Returns true if the line can be broken at this character. */
static bool is_wrap_space(gU16 c)
{
    return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '-';
}

#if MF_USE_ADVANCED_WORDWRAP

/* Represents a single word and the whitespace after it. */
struct wordlen_s
{
    gI16 word; /* Length of the word in pixels. */
    gI16 space; /* Length of the whitespace in pixels. */
    gU16 chars; /* Number of characters in word + space, combined. */
};

/* Take the next word from the string and compute its width.
 * Returns true if the word ends in a linebreak. */
static bool get_wordlen(const struct mf_font_s *font, mf_str *text,
                        struct wordlen_s *result)
{
    mf_char c;
    mf_str prev = *text;

    result->word = 0;
    result->space = 0;
    result->chars = 0;

    c = mf_getchar(text);
    while (c && !is_wrap_space(c))
    {
        result->chars++;
        result->word += mf_character_width(font, c);

		prev = *text;
        c = mf_getchar(text);
    }

    while (c && is_wrap_space(c))
    {
        result->chars++;

        if (c == ' ' || c == '-')
            result->space += mf_character_width(font, c);
        else if (c == '\t')
            result->space += mf_character_width(font, 'm') * MF_TABSIZE;
        else if (c == '\n') {
			/* Special case for newlines, skip the character then break. */
			prev = *text;
            break;
		}

        prev = *text;
        c = mf_getchar(text);
    }

    /* The last loop reads the first character of next word, put it back. */
    if (c)
        *text = prev;

    return (c == '\0' || c == '\n');
}

/* Represents the rendered length for a single line. */
struct linelen_s
{
    mf_str start; /* Start of the text for line. */
    gU16 chars; /* Total number of characters on the line. */
    gI16 width; /* Total length of all words + whitespace on the line in pixels. */
    bool linebreak; /* True if line ends in a linebreak */
    struct wordlen_s last_word; /* Last word on the line. */
    struct wordlen_s last_word_2; /* Second to last word on the line. */
};

/* Append word onto the line if it fits. If it would overflow, don't add and
 * return false. */
static bool append_word(const struct mf_font_s *font, gI16 width,
                        struct linelen_s *current, mf_str *text)
{
    mf_str tmp = *text;
    struct wordlen_s wordlen;
    bool linebreak;

    linebreak = get_wordlen(font, &tmp, &wordlen);

    if (current->width + wordlen.word <= width)
    {
        *text = tmp;
        current->last_word_2 = current->last_word;
        current->last_word = wordlen;
        current->linebreak = linebreak;
        current->chars += wordlen.chars;
        current->width += wordlen.word + wordlen.space;
        return true;
    }
    else
    {
        return false;
    }
}

/* Append a character to the line if it fits. */
static bool append_char(const struct mf_font_s *font, gI16 width,
                        struct linelen_s *current, mf_str *text)
{
    mf_str tmp = *text;
    mf_char c;
    gU16 w;

    c = mf_getchar(&tmp);
    w = mf_character_width(font, c);

    if (current->width + w <= width)
    {
        *text = tmp;
        current->chars++;
        current->width += w;
        return true;
    }
    else
    {
        return false;
    }
}

static gI32 sq16(gI16 x) { return (gI32)x * x; }

/* Try to balance the lines by potentially moving one word from the previous
 * line to the the current one. */
static void tune_lines(struct linelen_s *current, struct linelen_s *previous,
                       gI16 max_width)
{
    gI16 curw1, prevw1;
    gI16 curw2, prevw2;
    gI32 delta1, delta2;

    /* If the lines are rendered as is */
    curw1 = current->width - current->last_word.space;
    prevw1 = previous->width - previous->last_word.space;
    delta1 = sq16(max_width - prevw1) + sq16(max_width - curw1);

    /* If the last word is moved */
    curw2 = current->width + previous->last_word.word;
    prevw2 = previous->width - previous->last_word.word
                             - previous->last_word.space
                             - previous->last_word_2.space;
    delta2 = sq16(max_width - prevw2) + sq16(max_width - curw2);

    if (delta1 > delta2 && curw2 <= max_width)
    {
        /* Do the change. */
        gU16 chars;

        chars = previous->last_word.chars;
        previous->chars -= chars;
        current->chars += chars;
        previous->width -= previous->last_word.word + previous->last_word.space;
        current->width += previous->last_word.word + previous->last_word.space;
        previous->last_word = previous->last_word_2;

        while (chars--) mf_rewind(&current->start);
    }
}

void mf_wordwrap(const struct mf_font_s *font, gI16 width,
                 mf_str text, mf_line_callback_t callback, void *state)
{
    struct linelen_s current = { 0 };
    struct linelen_s previous = { 0 };
    bool full;
    gU32 giveUp = 2048;     /* Do while-loop a maximum of x times */

    current.start = text;

    while (*text)
    {
        full = !append_word(font, width, &current, &text);

        if (full || current.linebreak)
        {
            if (!current.chars)
            {
                /* We have a very long word. We must just cut it off at some
                 * point. */
                while (append_char(font, width, &current, &text));
            }

            if (previous.chars)
            {
                /* Tune the length and dispatch the previous line. */
                if (!previous.linebreak && !current.linebreak)
                    tune_lines(&current, &previous, width);

                if (!callback(previous.start, previous.chars, state))
                    return;
            }

            previous = current;
            current.start = text;
            current.chars = 0;
            current.width = 0;
            current.linebreak = false;
            current.last_word.word = 0;
            current.last_word.space = 0;
            current.last_word.chars = 0;
        }
        
        giveUp--;
        if (giveUp == 0)
        {
            break;
        }
    }

    /* Dispatch the last lines. */
    if (previous.chars)
    {
        if (!callback(previous.start, previous.chars, state))
            return;
    }

    if (current.chars)
        callback(current.start, current.chars, state);
}

#else

void mf_wordwrap(const struct mf_font_s *font, gI16 width,
                 mf_str text, mf_line_callback_t callback, void *state)
{
    mf_str linestart;

    /* Current line width and character count */
    gI16 lw_cur = 0, cc_cur = 0;

    /* Previous wrap point */
    gI16 cc_prev;
    mf_str ls_prev;

    linestart = text;

    while (*text)
    {
        cc_prev = 0;
        ls_prev = text;

        while (*text)
        {
            mf_char c;
            gI16 new_width;
            mf_str tmp;

            tmp = text;
            c = mf_getchar(&text);
            new_width = lw_cur + mf_character_width(font, c);

            if (c == '\n')
            {
                cc_prev = cc_cur + 1;
                ls_prev = text;
                break;
            }

            if (new_width > width)
            {
                text = tmp;
                break;
            }

            cc_cur++;
            lw_cur = new_width;

            if (is_wrap_space(c))
            {
                cc_prev = cc_cur;
                ls_prev = text;
            }
        }

        /* Handle unbreakable words */
        if (cc_prev == 0)
        {
            cc_prev = cc_cur;
            ls_prev = text;
        }

        if (!callback(linestart, cc_prev, state))
            return;

        linestart = ls_prev;
        text = linestart;
        lw_cur = 0;
        cc_cur = 0;
    }
}

#endif

#endif //MF_NO_COMPILE
