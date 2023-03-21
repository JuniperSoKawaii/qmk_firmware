// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp_lvgl.h"

void use_flex_row(void *obj);
void use_flex_column(void *obj);
void toggle_state(void *obj, lv_state_t state, bool enabled);
void toggle_hidden(void *obj, bool visible);
void resize_font(void *label, int32_t v);

void debug_set_obj_border(lv_obj_t *obj);
