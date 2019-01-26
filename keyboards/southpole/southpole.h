#pragma once

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, K018, K019, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117,       K119, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216,             K219, \
	K300, K301, K302,       K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316,             K319, \
	      K401, K402,       K404, K405, K406,             K409,                   K413,       K415, K416,             K419  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014,  K015,  K016,  K017,  K018,  K019 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116,  K117,  KC_NO, K119 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214,  K215,  K216,  KC_NO, KC_NO, K219 }, \
	{ K300,  K301,  K302,  KC_NO, K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  K313,  K314,  K315,  K316,  KC_NO, KC_NO, K319 }, \
	{ KC_NO, K401,  K402,  KC_NO, K404,  K405,  K406,  KC_NO, KC_NO, K409,  KC_NO, KC_NO, KC_NO, K413,  KC_NO, K415,  K416,  KC_NO, KC_NO, K419 }  \
}