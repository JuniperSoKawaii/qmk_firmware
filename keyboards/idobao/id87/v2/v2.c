// Copyright 2022 peepeetee (@peepeetee)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "v2.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { 102,   NO_LED,   101,   100,   99,   98,   97,   96,   95   }, //0
    { 70,   71,   72,   73,   74,   75,   76,   77,   78   }, //1
    { 69,   68,   67,   66,   65,   64,   63,   62,   61   }, //2
    { 40,   41,   42,   43,   44,   45,   46,   47,   48   }, //3
    { 39,   NO_LED,   38,   37,   36,   35,   34,   33,   32   }, //4
    { 16,   17,   18,   23,   22,   NO_LED,   19,   21,   20   }, //5
    { NO_LED,   87,   88,   90,   91,   92,   89,   93,   94   }, //6
    { 80,   86,   85,   83,   NO_LED,   82,   84,   81,   79   }, //7
    { NO_LED,   53,   54,   56,   57,   58,   55,   59,   60   }, //8
    { NO_LED,   NO_LED,   27,   52,   NO_LED,   51,   NO_LED,   50,   49   }, //9
    { NO_LED,   26,   25,   NO_LED,   28,   29,   24,   30,   31   } //A
}, {
    // LED Index to Physical Position
    {  13,  51 },{ 40,  51},{ 73,  51},{ 108,  51},{ 141,  51},{ 174,  51},{ 207,  51},
    { 207,  32},
    { 207,  13},{ 174,  13},{ 141,  13},{ 108,  13},{ 73,  13},{ 40,  13},{ 13,  13},
    { 13,  32},

{   8,  59 }, {  23,  59 }, {  38,  59 }, {  83,  59 }, { 129,  59 }, { 144,  59 }, { 159,  59 }, { 174,  59 }, { 193,  59 }, { 205,  59 }, { 217,  59 },
{ 205,  49 }, { 165,  49 }, { 142,  49 }, { 130,  49 }, { 118,  49 }, { 106,  49 }, {  94,  49 }, {  82,  49 }, {  70,  49 }, {  58,  49 }, {  46,  49 }, {  34,  49 }, {  14,  49 },
{  11,  39 }, {  28,  39 }, {  40,  39 }, {  52,  39 }, {  64,  39 }, {  76,  39 }, {  88,  39 }, { 100,  39 }, { 112,  39 }, { 124,  39 }, { 136,  39 }, { 148,  39 }, { 168,  39 },
{ 217,  30 }, { 205,  30 }, { 193,  30 }, { 172,  30 }, { 157,  30 }, { 145,  30 }, { 133,  30 }, { 121,  30 }, { 109,  30 }, {  97,  30 }, {  85,  30 }, {  73,  30 }, {  61,  30 }, {  49,  30 }, {  37,  30 }, {  25,  30 }, {  10,  30 },
{   7,  20 }, {  19,  20 }, {  31,  20 }, {  43,  20 }, {  55,  20 }, {  67,  20 }, {  79,  20 }, {  91,  20 }, { 103,  20 }, { 115,  20 }, { 127,  20 }, { 139,  20 }, { 151,  20 }, { 169,  20 }, { 193,  20 }, { 205,  20 }, { 217,  20 },
{ 217,   5 }, { 205,   5 }, { 193,   5 }, { 175,   5 }, { 163,   5 }, { 151,   5 }, { 139,   5 }, { 121,   5 },  { 109,   5 }, {  97,   5 },  {  85,   5 },  {  67,   5 }, {  55,   5 }, {  43,   5 }, {  31,   5 },{   7,   5 },
}, {
    // LED Index to Flag
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,

1,1,1,4,1,1,1,1,1,1,1,
1,1,4,4,4,4,4,4,4,4,4,4,1,
9,4,4,4,4,4,4,4,4,4,4,4,1,
1,1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,1,
4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,
1,9,1,4,4,4,4,1,1,1,1,4,4,4,4,1
} };

#endif
