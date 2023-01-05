 /* Copyright 2023 Laneware Peripherals
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */ 

#pragma once

#include "quantum.h"

/* ┌───┐┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐ ┌───┐
 * │000││001││002│003│004│005││006│007│008│009││010│011│012│013│ │014│  
 * └───┘└───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘ └───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
 * │100│101│102│103│104│105│106│107│108│109│110│111│112│  113  │ │115│  
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤  
 * │ 200 │201│202│203│204│205│206│207│208│209│210│211│212│ 213 │ │214│ 
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
 * │ 300  │301│302│303│304│305│306│307│308│309│310│311│  313   │ │314│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┘ ├───┤
 * │   400  │402│403│404│405│406│407│408│409│410│411│ 412  │┌───┐│414│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┘│413│└───┘
 * │ 500│ 501│ 502│          503           │504│505│506│┌───┼───┼───┐
 * └────┴────┴────┴────────────────────────┴───┴───┴───┘│507│508│509│
 *                                                      └───┴───┴───┘
 */

#define LAYOUT_ansi( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,       K115, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
    K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, \
	K500, K501, K502, K503, K504, K505, K506, K507, K508, K509  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,   K013,   K014}, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,   K113,   KC_NO,   K115 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,   K213,   K214}, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO,  K313,   K314}, \
	{ K400,  KC_NO, K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412,   K413,   K414},  \
    { K500,  K501,  K502,  K503,  K504,  K505,  K506,  K507,  K508,  K509}  \
}

/* ┌───┐┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐ ┌───┐
 * │000││001││002│003│004│005││006│007│008│009││010│011│012│013│ │014│  
 * └───┘└───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘ └───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
 * │100│101│102│103│104│105│106│107│108│109│110│111│112│113│114│ │115│  
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┤  
 * │ 200 │201│202│203│204│205│206│207│208│209│210│211│212│ 213 │ │214│ 
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ ├───┤
 * │ 300  │301│302│303│304│305│306│307│308│309│310│311│  313   │ │314│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┘ ├───┤
 * │   400  │402│403│404│405│406│407│408│409│410│411│ 412  │┌───┐│414│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┘│413│└───┘
 * │ 500│ 501│ 502│          503           │504│505│506│┌───┼───┼───┐
 * └────┴────┴────┴────────────────────────┴───┴───┴───┘│507│508│509│
 *                                                      └───┴───┴───┘
 */

#define LAYOUT_ansi_splitbs( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
    K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, \
    K500, K501, K502, K503, K504, K505, K506, K507, K508, K509  \
) { \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,   K013,   K014}, \
    { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,   K113,   K114,   K115 }, \
    { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,   K213,   K214}, \
    { K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO,  K313,   K314}, \
    { K400,  KC_NO, K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412,   K413,   K414},  \
    { K500,  K501,  K502,  K503,  K504,  K505,  K506,  K507,  K508,  K509}  \
}

/* ┌───┐┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐ ┌───┐
 * │000││001││002│003│004│005││006│007│008│009││010│011│012│013│ │014│  
 * └───┘└───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘ └───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┐
 * │100│101│102│103│104│105│106│107│108│109│110│111│112│  113  │ │115│  
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┤  
 * │ 200 │201│202│203│204│205│206│207│208│209│210│211│212│ 313 │ │214│ 
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │ ├───┤
 * │ 300  │301│302│303│304│305│306│307│308│309│310│311│312│    │ │314│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┘ ├───┤
 * │ 400│401│402│403│404│405│406│407│408│409│410│411│ 412  │┌───┐│414│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┘│413│└───┘
 * │ 500│ 501│ 502│          503           │504│505│506│┌───┼───┼───┐
 * └────┴────┴────┴────────────────────────┴───┴───┴───┘│507│508│509│
 *                                                      └───┴───┴───┘
 */

#define LAYOUT_iso( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,       K115, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,       K214,\
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, \
    K500, K501, K502, K503, K504, K505, K506, K507, K508, K509  \
) { \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,   K013,   K014}, \
    { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,   K113,   KC_NO,   K115 }, \
    { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,   KC_NO,  K214}, \
    { K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,   K313,   K314}, \
    { K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412,   K413,   K414},  \
    { K500,  K501,  K502,  K503,  K504,  K505,  K506,  K507,  K508,  K509}  \
}

/* ┌───┐┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐ ┌───┐
 * │000││001││002│003│004│005││006│007│008│009││010│011│012│013│ │014│  
 * └───┘└───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘ └───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┐
 * │100│101│102│103│104│105│106│107│108│109│110│111│112│113│114│ │115│  
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┤  
 * │ 200 │201│202│203│204│205│206│207│208│209│210│211│212│ 313 │ │214│ 
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │ ├───┤
 * │ 300  │301│302│303│304│305│306│307│308│309│310│311│312│    │ │314│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┘ ├───┤
 * │ 400│401│402│403│404│405│406│407│408│409│410│411│ 412  │┌───┐│414│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┘│413│└───┘
 * │ 500│ 501│ 502│          503           │504│505│506│┌───┼───┼───┐
 * └────┴────┴────┴────────────────────────┴───┴───┴───┘│507│508│509│
 *                                                      └───┴───┴───┘
 */

#define LAYOUT_iso_splitbs( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,       K214,\
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413, K414, \
    K500, K501, K502, K503, K504, K505, K506, K507, K508, K509  \
) { \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,   K013,   K014}, \
    { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,   K113,   K114,    K115 }, \
    { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,   KC_NO,  K214}, \
    { K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,   K313,   K314}, \
    { K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412,   K413,   K414},  \
    { K500,  K501,  K502,  K503,  K504,  K505,  K506,  K507,  K508,  K509}  \
}
