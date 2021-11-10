# DZ60

My second keyboard edit. A multi-layer ANSI-60 with layers and function shift on each layer.
Changes from the default keymap include moving RESET, and a prefered arangement for the cusor
block of keys. The function key was exchanged with the right control key to get it. This makes the layout of the right modifiers left to rignt be alt/win/control/Fn.

## Right Windows is Application Context Menu Instead
The right Windows key is for getting the application context menu. The right Windows GUI
key is not often used. It is available on the macroboard shift layer for completeness.

## Common to All Fn Layers
* If on an Fn layer a switch is not necessary so the following keys become themselves.
* Left control is ANSI layer select. Basic conformist ANSI.
* Left win is macroboard layer select.
* Left alt is navigation layer select. You MUST be in this mode for **BQN**.

## ANSI Layer
* Right control exchanged with function shift key as always.

### ANSI Shift Layer (Fn ANSI)
* Scroll lock placed on caps lock.
* Right alt/win/control/slash form cusor block.
* Backslash is insert.
* Backspace is delete.
* F1 to F12 form top row numbers and minus/equals.
* Square brackets are home and end.
* Comma and period are page up/down.
* Semicolon is pause.
* Apostrophy is print screen.
* RGB controls are Q-I.
* Backlight controls are C-N.
* Backtick is excape.
* Various unicode characters µ/ℎ(M), °/⦵(K), £/€(L), ω/Ω(Z), ∫/Σ(S), ∂/∇(D) and √/∛(G).
* System power down on P key.
* Global mute is X.
* Browser home key is O, search is A, favorites is F.
* Volume is up(J) and down(H).

## Macroboard Layer
* Escape is a one shot sticky alt shift.
* Tab is a one shot sticky control alt.
* Caps lock is a one shot sticky control shift.
* All modifiers are one shot sticky.
* Function shift is a toggle to the shifted layer.
* F1 to F12 form top row numbers and minus/equals.
* F13 to F24 form second row Q-].
* F1 to F12 form third row A-enter with an implicit right alt gr applied.
* F13 to F23 form fourth row Z-right shift with an implicit right alt gr applied.
* Backslash is F24 with an implicit right alt gr applied.
* Depending on your system the "Level 3 Shift" may be removed by localization of alt gr.
* Right alt/control are alt tab window switch (reverse and forward).
* Right win key is the right win key and not the app context menu key as in other layers.

### Macroboard Shift Layer (Fn Macroboard)
* The right win key is one shot sticky. 
* Escape is a one shot sticky win alt shift.
* Tab is a one shot sticky win control alt.
* Caps lock is a one shot sticky win control shift.
* Left shift is a one shot sticky win shift.
* Backspace is a one shot sticky control alt shift.
* Fn is still sticky and needs pressing to exit the layer shift.
* Right control enters the extended shift layer.
* Right alt enters the special shift layer.

### Extended Shift Layer
* Fn exits the extended shift layer.
* Right alt/win/control/slash form mouse movement block.
* Period is left mouse button.
* Right shift is right mouse button.
* All left modifiers are normal with no one shot sticky.
* Enter and backspace are themselves.
* Backslash is keyboard reset.
* Equals is numpad equals (for extra macro codes when possible).
* Comma is numpad comma.
* The brackets are scroll wheel up and down such the [ is up.
* Quote is the scroll button.
* Semicolon is auxilliary mouse button 4 (standard mice don't have this).
* All the alpha keys are themselves.
* Minus turns on key lock for the next key (for easier drag 'n' drop for example).

### Special Shift Layer
* Fn exits the special shift layer.
* P and equals is korean modifiers.
* Minus is key lock for holding down a key until the held key is pressed again.
* International modifiers are on Q-O.
* Numbers are the numpad numbers for macro code options.
* Remaining laguage 3 to 7 are on Z-M.
* All left and right modifiers are themselves.
* Comma/period/slash set moise acceleration 1, 2 and 3.
* Backspace is delete.
* Backslash is insert. 
* Square brackets are home and end.
* Enter is itself.
* Various unicode characters µ/ℎ(M), °/⦵(K), £/€(L), ω/Ω(Z), ∫/Σ(S), ∂/∇(D) and √/∛(G).
* Volume is up(J) and down(H).
* Browser search is A, favorites is F.
* Escape is pure escape.
* Caps lock is num lock.

#### Notes on "Level 3 Shift"
* Ironically not being American I will not test the en_US local without hardware.
* I'm not sure if that locale supports an alt gr key interpretation of right alt.
* Hacking linux termcap/gui equivalent files might be possible for the determined.
* I call it WANKSI for fun! (Worldwide American National Keyboard Standards Institue).
* I hear they have a galactic space force branch.
* I'm sure I've included all the language and international keys for `galactic` languages.
* I think the Unicode allocation for planet Earth is a galactic joke.
* A universal joke perhaps, with overtones of differentiation through gravity wells.
* The level 4 shifts are all lockable on P, while a minus on mouse is more 13th letter freq.
* Q is the 26th in popularity by frequency count but first left/right, top/bottom.

```The inventor of Morse code, Samuel Morse (1791-1872), needed to know this so that he could give the simplest codes to the most frequently used letters. He did it simply by counting the number of letters in sets of printers' type. The figures he came up with were:	
12,000	E               2,500	F
9,000	T	            2,000	W, Y
8,000	A, I, N, O, S	1,700	G, P
6,400	H	            1,600	B
6,200	R	            1,200	V
4,400	D	            800	K
4,000	L	            500	Q
3,400	U	            400	J, X
3,000	C, M	        200	Z
```

```For word games, it is often the frequency of letters in English vocabulary, regardless of word frequency, which is of more interest. The following is a result of an analysis of the letters occurring in the words listed in the main entries of the Concise Oxford Dictionary (9th edition, 1995) and came up with the following table:	
E	11.1607%	56.88	M	3.0129%	15.36
A	8.4966%	43.31	H	3.0034%	15.31
R	7.5809%	38.64	G	2.4705%	12.59
I	7.5448%	38.45	B	2.0720%	10.56
O	7.1635%	36.51	F	1.8121%	9.24
T	6.9509%	35.43	Y	1.7779%	9.06
N	6.6544%	33.92	W	1.2899%	6.57
S	5.7351%	29.23	K	1.1016%	5.61
L	5.4893%	27.98	V	1.0074%	5.13
C	4.5388%	23.13	X	0.2902%	1.48
U	3.6308%	18.51	Z	0.2722%	1.39
D	3.3844%	17.25	J	0.1965%	1.00
P	3.1671%	16.14	Q	0.1962%	(1)
```

* Did you know that there are 26 simple sporadic groups?
* Is space the 27th honorary tits group?
* Has it been a mamalian while in the mamalian `Milky Way`?

## Navigation Layer
* Right alt/win/control/slash form cusor block.
* Blackslash enters a prefix to enter **BQN** characters.

### Navigation Shift Layer (Fn Navigation)
* Scroll lock placed on caps lock.
* Backslash is insert.
* Backspace is delete.
* F1 to F12 form top row numbers and minus/equals.
* F13 to F24 form second row Q-].
* Comma and period are page up/down.
* Semicolon is pause.
* Apostrophy is print screen.
* Backtick is excape.
* Enter is pure escape for easy shift escape typing.
* Right control/alt function as modifiers for F1-F24 usage.
* Various unicode characters µ/ℎ(M), °/⦵(K), £/€(L), ω/Ω(Z), ∫/Σ(S), ∂/∇(D) and √/∛(G).
* Media control prev(C), play(V), next(B), launch(N).
* Global mute is X.
* Browser search is A, favorites is F.
* Volume is up(J) and down(H).

## BQN Layer
* BQN unshifted and shifted.
* Fn shift holds the BQN layer.
* Left ontrol/win/alt prefix meta of **\\** to select further layers.
* Left and right cursor work on right alt/control.
* Right GUI button is right win key.
* By default 2021-11-08 the user layers are not programmed.

### Control Shift Layer (BQN Left Control)
* Various control code literals and icongraphs with cursor.
* Comma and period are page up/down.
* Semicolon is pause.
* Apostrophy is print screen.

## Unicode Shift Layer (BQN Left Alt)
* Unicode selection on alphas.
* Numbers unchanged.
* Square brackets are home and end.
* Comma and period are page up/down.
* Semicolon is pause.
* Apostrophy is print screen.

## Old Keys for the Young
* As everyone knows ecape has two purposes.
* EscA when running, stop and queue for analysis or bulk closure later.
* EscB when coding it's the best of origional ASCII for encode something extending the limited system.
* A what follows is not conformal to assuptions of the past or limits of the present literal.
* EscC I've got VIM :D.
* Windows is the OS respond key.
* Control (produces escape control+[) but few codes are used these days (enter/esc/tab/backspace/escape).
* Some codes got reused for cut/copy/paste etc.
* But `<H1>` is more commom than control+A (origional purpose) these days (circa 2020).
* Control+M is a funny example (but depends on application level interpretation), as is multimedia control+G.
* Alt enters the alternate expression space and covers a more modern escape at the language level instead of the binary system level and replace (SI and SO control ASCII).
* Optimal control replacements such as control+S should redefine the lower 32 symbols.
* Various combinations not locked by a priority (high priority ordernate OS > intermediate Language > low level App) should do anything if available to assign.
* Level 3 shift just inserts a more expressive (in intent) layer between win and alt.
* So why is low level control of application easier to find?
* What control+alt+delete used to do?
* Apply application control with and alternate linguistic meaning of delete by by stopping the single task that was possible without terminate and stay resident jot key apps.
* With 32 bits perhaps to indicate a lingual star system before the alternate becomes the locale zone of the expression required to be currently typed, it is critical to reduce the codepage size to get even some sort of eventual recognition in a galaxy that might have life, planets and competing languages upon just one planet.
* Of course document language tags will have to be maintained by the OS as the applications literally don't care much beyond a basic control code set embedded within the text. This reduces the document size but does need one of the control codes to kind of be alt, one to be alt gr and one to be OS system request.
* Say control+S embedded should indicate (possibly ignored as virii exist) the desire to save the following by some means and persistance specification.
* Post moderner computing should not be a history project.
* Should an embedded control+A keyword for automatic registration with a search? So that all planet wide might find it reprocessed through a meaning filter to become relevantly formatted even before the vanity of waiting for a publication commit beyond the control+A inserted as a literal character?
* To embed? To escape the non literal hotkey mode and enter placer mode. It would need an escape that could never be placed and does explain the control+[ and the go back to literal hotkey mode control+].
* And the `unplacable` in the knowledge it could be placed without consequence apart from its between became a separation of grouped things. And the dreams were so big and the future so far.
* Ironically the escape was almost unplacable but was placed in files as the escape worked opposite to how things were. The escape (not literal but semantical) character in many programming languages is \ which is not an accident. It just stops interpretation of the following and lets it pass. It really should be called file escape and allows placing of control+] as it is preceded by control+\ in a file in a next only, once instance overide. In this sense it should be called ignore override.
* Why not use contol+] to replace control+\? Indeeed it might work if you kept track of what level you were at or if you didn't join mudstream. Control+^ or record separator defined the separation of recording and so reset the escape ment to the default. It perhaps should be called record initialize and perhaps logically close any previous escapement state.
* Control+_ perhaps encompases a new coding logic is required. So not only has the escapement to be reset but the processing on the next recording has to be changed. This could obviously be tracked by counting, but if you joined midstream or performed a partial file recovery then you'd have to know when a new coding algorithm was used based on this synchronization of normal start of the recording groupings based on the expectation of regaining a new counter resynchronization with the atomic undividable unit.
* And to control+@ the null character which id a terminal and so a separator. It could have easily been control+] and the difference is an obviousness of the handling of a previous control+[ where the control+@ would not care when being entered. This would make control+] be a system convinience as use as a separator on some streams and as a non-written output on escaped streams. What would happen if you fed one kind into the other?
* oh yes, and if you don't know how long a steam is you can't prefix it with its length without a transmission delay based on its length. This would introduce latency.
* The rest are letra-gimp. This includes DEL or control-? which is just a recycling prevention mechanism by scribbling over a mistake so that a new recording arrangement does not need to be made with it not there. In this sense its origional meaning is less than control+@, and is more a kin to an erase and ignore to not have to fragment or collect to shorten. It was repurposed by the fancy ability to even remove it from the data making the delete disapper keeping the bit in front of it the same size. As it's ignorable it does not matter if it is removed unless someone took the trobule to count and the length would be off by a DEL or few if they weren't there.

The `control_codes.md` contains more information about control codes.
