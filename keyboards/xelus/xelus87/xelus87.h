#pragma once

#include "quantum.h"

#define ____ KC_NO

#define LAYOUT_all( \
    K000,       K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013,   K014, K015, K016, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,   K114, K115, K116, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,   K214, K215, K216, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313,                     \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410,       K412,               K415,       \
    K500, K501, K502,             K505,                   K509, K510,       K512, K513,   K514, K515, K516  \
) { \
    { K000, ____, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, ____, K313, ____, ____, ____ }, \
    { K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, ____, K412, ____, ____, K415, ____ }, \
    { K500, K501, K502, ____, ____, K505, ____, ____, ____, K509, K510, ____, K512, K513, K514, K515, K516 }  \
}
