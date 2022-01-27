/*
 * @Description    : 
 * @version        : 
 * @Author         : JunLee
 * @Date           : 2022-01-06 14:34:42
 * @LastEditTime   : 2022-01-27 11:34:00
 * @FilePath       : \qmk_firmware\keyboards\7liang\tp32\tp32.c
 */
// Copyright 2022 Pkerr (@sky_jun@qq.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "tp32.h"

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((week))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
};
#endif
