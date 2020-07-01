#ifndef AFTER_H
#define AFTER_H

#include "quantum.h"
//#define XXX KC_NO
//include the above later to optimize after.h file
//lets me use xxx instead of kc_no

#define LAYOUT_all( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,       K115, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,             K215, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310,       K312, K313,       K315, \
	K400,       K402,             K405,                   K409, K410,       K412, K413,       K415  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014,  K015 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  KC_NO, K115 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  KC_NO, KC_NO, K215 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  KC_NO, K312,  K313,  KC_NO, K315 }, \
	{ K400,  KC_NO, K402,  KC_NO, KC_NO, K405,  KC_NO, KC_NO, KC_NO, K409,  K410,  KC_NO, K412,  K413,  KC_NO, K415 }  \
}

#endif