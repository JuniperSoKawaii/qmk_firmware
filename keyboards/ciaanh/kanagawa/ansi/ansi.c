/* Copyright 2023 Ciaanh (@ciaanh)
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
 
 #include "kanagawa.h"

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_LED_COUNT 82

    led_config_t g_led_config = {    
    {
        // Key Matrix to LED Index
        { 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0, NA }, 
        { 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13 }, 
        { 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27 }, 
        { 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 66 }, 
        { 65, NA, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 67 }, 
        { 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68 }  
    }, 

    {
        // LED Index to Physical Position
                            {189,  0},  {175,  0},  {161,  0},  {147,  0},  {126,  0},  {112,  0},  { 98,  0},  { 84,  0},  { 63,  0},  { 49,  0},  { 35,  0},  { 21,  0},  {  0,  0}, 
                {189, 12},  {168, 12},  {154, 12},  {140, 12},  {126, 12},  {112, 12},  { 98, 12},  { 84, 12},  { 70, 12},  { 56, 12},  { 42, 12},  { 28, 12},  { 14, 12},  {  0, 12}, 
                {189, 23},  {179, 23},  {161, 23},  {147, 23},  {133, 23},  {119, 23},  {105, 23},  { 91, 23},  { 77, 23},  { 63, 23},  { 49, 23},  { 35, 23},  { 21, 23},  {  4, 23}, 
                {187, 35},  {165, 35},  {151, 35},  {137, 35},  {123, 35},  {109, 35},  { 95, 35},  { 81, 35},  { 67, 35},  { 53, 35},  { 39, 35},  { 25, 35},        {  5, 35}, 
                {177, 47},  {158, 47},  {144, 47},  {130, 47},  {116, 47},  {102, 47},  { 88, 47},  { 74, 47},  { 60, 47},  { 46, 47},  { 32, 47},          {  9,  47}, 
{224, 12},                           
{224, 23},                           
{224, 35},                           
        {214, 61},                         
        {200, 49},  {200, 61},  {186, 61},      {168, 58},  {154, 58},  {140, 58},          {114, 64},      { 82, 64},                  { 70, 58},  { 32, 58},  { 16, 58},  {  0, 58}, 
 
    }, 

    {
        // LED Index to Flag
           4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
           4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
           4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  1,
        4,
        4,
        4, 4, 
              4, 4, 4, 1, 1, 1, 4, 4, 1, 1, 1, 1,
    }};
#endif 