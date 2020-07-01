#pragma once

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003,       K005, K006, K007, K008, K009, K010, K011, K012, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209,       K211,       \
	K300, K301, K302, K303,       K305, K306, K307, K308,       K310, K311, K312  \
) { \
	{ K000,  K001,  K002,  K003,  KC_NO, K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  KC_NO, K211,  KC_NO }, \
	{ K300,  K301,  K302,  K303,  KC_NO, K305,  K306,  K307,  K308,  KC_NO, K310,  K311,  K312 }  \
}
