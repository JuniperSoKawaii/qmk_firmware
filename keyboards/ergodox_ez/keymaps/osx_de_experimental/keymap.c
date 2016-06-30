#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "led.h"
#include "action_util.h"
#include "mousekey.h"
#include "timer.h"
#include "keymap_plover.h"
#include "keymap_extras/keymap_french.h"
#include "keymap_extras/keymap_neo2.h"
#include "keymap_extras/keymap_uk.h"
#include "keymap_extras/keymap_colemak.h"
#include "keymap_extras/keymap_french_osx.h"
#include "keymap_extras/keymap_nordic.h"
#include "keymap_extras/keymap_dvorak.h"
#include "keymap_extras/keymap_german.h"
#include "keymap_extras/keymap_norwegian.h"
#include "keymap_extras/keymap_german_osx.h"
#include "keymap_extras/keymap_spanish.h"
#include "keymap_extras/keymap_bepo.h"


/**
* This layout was generated using the ErgodoxLayoutGenerator (ELG). You can download it from https://github.com/sboesebeck/ErgodoxLayoutGenerator/releases
* documentation about it can be found here https://boesebeck.name/2016/04/16/ergodoxlayoutgenerator-documentation/
* Thanks to the team of Erez Zukerman for building the great Ergodox-EZ!
*
* use at own risk!
**/

#define BASE 0
#define SYMB 1
#define MDIA 2
#define SMLY 3
#define NUMB 4
#define EGOS 5

#define SMLY_TOG_QUOT 0

#define M_TOGGLE_5 1

#define TGH_NUM 2

#define M_DE_OSX_PLUS_CTRLALT 3

#define SM_KISS 4

#define SM_FROWN 5

#define SM_CRY 6

#define SM_SMILE 7

#define SM_SMIRK 8

#define M_Key_KC_BSLS_MODS 9

#define M_LGUI_SHFT 10

#define SM_HEART 11

#define TOG_HLD_MDIA 12

#define SM_LAUGH 13

#define SM_SAD 14

#define M_DE_OSX_CIRC_CTRLCMD 15

#define M_MEH_SH_ACUT 16


//Layout keymap.c generated with ErgodoxLayoutGenerator V1.0BETA1
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/**
* Layer: BASE
* /-------------------//-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/                        /-------------------//-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/                       
* | ESC                | 1                  | 2                  | 3                  | 4                  | 5                  | ONEShot            |                       | OS MDIA            | 6                  | 7                  | 8                  | 9                  | 0                  | ß                  |                      
* |                    |                    |                    |                    |                    |                    | NUMB               |                       |                    |                    |                    |                    |                    |                    |                    |                      
* /-------------------//-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/                        /-------------------//-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/                       
* | TAB                | Q                  | W                  | E                  | R                  | T                  | Cmd                |                       | Cmd                | Z                  | U                  | I                  | O                  | P                  | Ü                  |                      
* |                    |                    |                    |                    |                    |                    |                    |                       |                    |                    |                    |                    |                    |                    |                    |                      
* /-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/\-------------------\                        \-------------------\/-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/                       
* | Alt                | A                  | S                  | D                  | F                  | G                  |                                                                 | H                  | J                  | K                  | L                  | Ö                  | Ä                  |                      
* |                    |                    |                    |                    |                    |                    |                                                                 |                    |                    |                    |                    |                    | ALT                |                      
* /-------------------//-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/                        /-------------------//-------------------//-------------------//-------------------//-------------------//-------------------//-------------------/                       
* | Shift              | Y                  | X                  | C                  | V                  | B                  | NO                 |                       | NO                 | N                  | M                  | ,                  | .                  | -                  | Shift              |                      
* |                    | Ctrl               |                    |                    |                    |                    | Meh                |                       | Hyper              |                    |                    |                    |                    | Ctrl               |                    |                      
* \-------------------\\-------------------\\-------------------\\-------------------\\-------------------\\-------------------\\-------------------\                        \-------------------\\-------------------\\-------------------\\-------------------\\-------------------\\-------------------\\-------------------/
*                                                                                                                                                                                                                                                                                                                                                      
*                                                                                                                                                                                                                                                                                                                                                      
*                                           /-------------------//-------------------//-------------------//-------------------//-------------------/                                                                                       /-------------------//-------------------//-------------------//-------------------//-------------------/  
*                                           | <                  | LongPress / Type   | Ctrl + Alt         | Shift+Ctrl         | One Shot           |                                                                                      | LongPress / Type   | CMD+Shift          | ALT+Shift          | Acut               | +                  | 
*                                           | SYMB               | DE_OSX_CIRC_CTRLCMD|                    |                    |        SMLY        |                                                                                      | Key_BSLS_MODS      |                    |                    |                    | SYMB               | 
*                                           \-------------------\\-------------------\\-------------------\\-------------------\/-------------------//-------------------/   /-------------------//-------------------/                     \-------------------\\-------------------\\-------------------\\-------------------\\-------------------/ 
*                                                                                                                               | HOME               | END                |  | LEFT               | RIGHT              |                                                                                                                               
*                                                                                                                               |                    |                    |  |                    |                    |                                                                                                                               
*                                                                                                                               \-------------------\/-------------------/   /-------------------/\-------------------/                                                                                                                                
*                                                                                                                                                    | PGUP               |  | UP                 |                                                                                                                                                    
*                                                                                                                                                    |                    |  |                    |                                                                                                                                                    
*                                                                                                          /-------------------//-------------------//-------------------/   /-------------------//-------------------//-------------------/                                                                                                           
*                                                                                                          | BSPC               | DEL                | PGDN               |  | DOWN               | ENT                | SPC                |                                                                                                          
*                                                                                                          |                    |                    |                    |  |                    |                    |                    |                                                                                                          
*                                                                                                          \-------------------\\-------------------\\-------------------\   \-------------------\\-------------------\\-------------------/
*                                                                                                                                                                                                                                                                                                                                                      
* 
**/
[BASE]=KEYMAP(
//left half
    KC_ESC, DE_OSX_1, DE_OSX_2, DE_OSX_3, DE_OSX_4, DE_OSX_5, KC_LEAD, 
    KC_TAB, DE_OSX_Q, DE_OSX_W, DE_OSX_E, DE_OSX_R, DE_OSX_T, KC_LGUI, 
    KC_LALT, DE_OSX_A, DE_OSX_S, DE_OSX_D, DE_OSX_F, DE_OSX_G, 
    KC_LSFT, CTL_T(DE_OSX_Y), DE_OSX_X, DE_OSX_C, DE_OSX_V, DE_OSX_B, MEH_T(KC_NO), 
                  LT(SYMB,DE_OSX_LESS), M(M_DE_OSX_CIRC_CTRLCMD), LCTL(KC_LALT), LSFT(KC_LCTRL), OSL(SMLY), 
                                              KC_HOME, KC_END, 
                                                     KC_PGUP, 
                                       KC_BSPC, KC_DEL, KC_PGDN, 
    //right half
    OSL(MDIA), DE_OSX_6, DE_OSX_7, DE_OSX_8, DE_OSX_9, DE_OSX_0, DE_OSX_SS, 
    KC_RGUI, DE_OSX_Z, DE_OSX_U, DE_OSX_I, DE_OSX_O, DE_OSX_P, DE_OSX_UE, 
           DE_OSX_H, DE_OSX_J, DE_OSX_K, DE_OSX_L, DE_OSX_OE, ALT_T(DE_OSX_AE), 
    ALL_T(KC_NO), DE_OSX_N, DE_OSX_M, DE_OSX_COMM, DE_OSX_DOT, CTL_T(DE_OSX_MINS), KC_RSFT, 
                         M(M_Key_KC_BSLS_MODS),  LGUI(KC_LSFT), LALT(KC_LSFT), DE_OSX_ACUT,LT(SYMB,DE_OSX_PLUS), 
    KC_LEFT, KC_RIGHT, 
    KC_UP, 
    KC_DOWN, KC_ENT, KC_SPC),
/**
* Layer: SYMB
* /-----------//-----------//-----------//-----------//-----------//-----------//-----------/                /-----------//-----------//-----------//-----------//-----------//-----------//-----------/               
* | APPLICATION| F1         | F2         | F3         | F4         | F5         | F5         |               | F6         | F6         | F7         | F8         | F9         | F10        | F11        |              
* |            |            |            |            |            |            |            |               |            |            |            |            |            |            |            |              
* /-----------//-----------//-----------//-----------//-----------//-----------//-----------/                /-----------//-----------//-----------//-----------//-----------//-----------//-----------/               
* |            | <          | >          | !          | ?          |            |            |               |            | \          | [          | ]          | <          | >          | !          |              
* |            |            |            |            |            |            |            |               |            |            |            |            |            |            |            |              
* /-----------//-----------//-----------//-----------//-----------//-----------/\-----------\                \-----------\/-----------//-----------//-----------//-----------//-----------//-----------/               
* |            | #          | $          | \          | /          | .          |                                         | /          | (          | )          | {          | }          | #          |              
* |            |            |            |            |            |            |                                         |            |            |            |            |            |            |              
* /-----------//-----------//-----------//-----------//-----------//-----------//-----------/                /-----------//-----------//-----------//-----------//-----------//-----------//-----------/               
* |            |            | <          | %          | |          | ~          |            |               |            | |          | ~          |            |            |            |            |              
* |            |            |            |            |            |            |            |               |            |            |            |            |            |            |            |              
* \-----------\\-----------\\-----------\\-----------\\-----------\\-----------\\-----------\                \-----------\\-----------\\-----------\\-----------\\-----------\\-----------\\-----------\
*                                                                                                                                                                                                                      
*                                                                                                                                                                                                                      
*                           /-----------//-----------//-----------//-----------//-----------/                                                       /-----------//-----------//-----------//-----------//-----------/  
*                           |            |            |            |            |            |                                                      | '          | DQOT       |            | Toggle 5   |            | 
*                           |            |            |            |            |            |                                                      |            |            |            |            |            | 
*                           \-----------\\-----------\\-----------\\-----------\/-----------//-----------/   /-----------//-----------/             \-----------\\-----------\\-----------\\-----------\\-----------\
*                                                                               |            |            |  | F13        | F12        |                                                                               
*                                                                               |            |            |  |            |            |                                                                              
*                                                                               \-----------\/-----------/   /-----------/\----------- 
*                                                                                            |            |  | F14        |                                                                                            
*                                                                                            |            |  |            |                                                                                            
*                                                                  /-----------//-----------//-----------/   /-----------//-----------//-----------/                                                                   
*                                                                  |            | DEL        |            |  | F15        |            |            |                                                                  
*                                                                  |            |            |            |  |            |            |            |                                                                  
*                                                                  \-----------\\-----------\\-----------\   \-----------\\-----------\\-----------
*                                                                                                                                                                                                                      
* 
**/
[SYMB]=KEYMAP(
//left half
    KC_APPLICATION, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F5, 
    KC_TRNS, DE_OSX_LESS, DE_OSX_MORE, DE_OSX_EXLM, DE_OSX_QST, KC_TRNS, KC_TRNS, 
    KC_TRNS, DE_OSX_HASH, DE_OSX_DLR, DE_OSX_BSLS, DE_OSX_SLSH, KC_DOT, 
    KC_TRNS, KC_TRNS, DE_OSX_LESS, DE_OSX_PERC, DE_OSX_PIPE, DE_OSX_TILD, KC_TRNS, 
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                              KC_TRNS, KC_TRNS, 
                                                     KC_TRNS, 
                                       KC_TRNS, KC_DEL, KC_TRNS, 
    //right half
    KC_F6, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
    KC_TRNS, DE_OSX_BSLS, DE_OSX_LBRC, DE_OSX_RBRC, DE_OSX_LESS, DE_OSX_MORE, DE_OSX_EXLM, 
           DE_OSX_SLSH, DE_OSX_LPRN, DE_OSX_RPRN, DE_OSX_LCBR, DE_OSX_RCBR, DE_OSX_HASH, 
    KC_TRNS, DE_OSX_PIPE, DE_OSX_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                         DE_OSX_QUOT, DE_OSX_DQOT, KC_TRNS, M(M_TOGGLE_5), KC_TRNS, 
    KC_F13, KC_F12, 
    KC_F14, 
    KC_F15, KC_TRNS, KC_TRNS),
/**
* Layer: MDIA
* /-----//-----//-----//-----//-----//-----//-----/          /-----//-----//-----//-----//-----//-----//-----/         
* |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |        
* |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |        
* /-----//-----//-----//-----//-----//-----//-----/          /-----//-----//-----//-----//-----//-----//-----/         
* |      |      | BTN1 | U    | BTN2 | U    |      |         |      |      |      |      |      |      |      |        
* |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |        
* /-----//-----//-----//-----//-----//-----/\-----\          \-----\/-----//-----//-----//-----//-----//-----/         
* |      |      | L    | D    | R    | D    |                       |      |      |      |      |      |      |        
* |      |      |      |      |      |      |                       |      |      |      |      |      |      |        
* /-----//-----//-----//-----//-----//-----//-----/          /-----//-----//-----//-----//-----//-----//-----/         
* |      |      | L    | D    | R    | BTN3 |      |         |      |      |      |      |      | UP   |      |        
* |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |        
* \-----\\-----\\-----\\-----\\-----\\-----\\-----\          \-----\\-----\\-----\\-----\\-----\\-----\\-----
*                                                                                                                      
*                                                                                                                      
*               /-----//-----//-----//-----//-----/                               /-----//-----//-----//-----//-----/  
*               |      |      |      |      |      |                              |      |      | LEFT | DOWN | RIGHT| 
*               |      |      |      |      |      |                              |      |      |      |      |      | 
*               \-----\\-----\\-----\\-----\/-----//-----/   /-----//-----/       \-----\\-----\\-----\\-----\\-----/
*                                           |      |      |  | MPRV | MNXT |                                           
*                                           |      |      |  |      |      |                                           
*                                           \-----\/-----/   /-----/\-----/
*                                                  |      |  | VOLU |                                                  
*                                                  |      |  |      |                                                  
*                                    /-----//-----//-----/   /-----//-----//-----/                                     
*                                    |      |      |      |  | VOLD | MUTE | MPLY |                                    
*                                    |      |      |      |  |      |      |      |                                    
*                                    \-----\\-----\\-----\   \-----\\-----\\-----/                                     
*                                                                                                                      
* 
**/
[MDIA]=KEYMAP(
//left half
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, 
    KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_BTN3, KC_TRNS, 
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                              KC_TRNS, KC_TRNS, 
                                                     KC_TRNS, 
                                       KC_TRNS, KC_TRNS, KC_TRNS, 
    //right half
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, 
                         KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, 
    KC_MPRV, KC_MNXT, 
    KC_VOLU, 
    KC_VOLD, KC_MUTE, KC_MPLY),
/**
* Layer: SMLY
* /--------//--------//--------//--------//--------//--------//--------/             /--------//--------//--------//--------//--------//--------//--------/            
* |         |         |         |         |         |         |         |            | Typing  | Typing  |         |         |         |         |         |           
* |         |         |         |         |         |         |         |            | SM_KISS | SM_HEART|         |         |         |         |         |           
* /--------//--------//--------//--------//--------//--------//--------/             /--------//--------//--------//--------//--------//--------//--------/            
* |         |         |         |         |         |         |         |            |         | Typing  | Typing  | Typing  |         |         |         |           
* |         |         |         |         |         |         |         |            |         | SM_FROWN| SM_SAD  | SM_CRY  |         |         |         |           
* /--------//--------//--------//--------//--------//--------/\--------\             \--------\/--------//--------//--------//--------//--------//--------/            
* |         |         |         |         |         |         |                                | Typing  | Typing  | Typing  |         |         |         |           
* |         |         |         |         |         |         |                                | SM_SMIRK| SM_SMILE| SM_LAUGH|         |         |         |           
* /--------//--------//--------//--------//--------//--------//--------/             /--------//--------//--------//--------//--------//--------//--------/            
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* \--------\\--------\\--------\\--------\\--------\\--------\\--------\             \--------\\--------\\--------\\--------\\--------\\--------\\--------\            
*                                                                                                                                                                      
*                                                                                                                                                                      
*                     /--------//--------//--------//--------//--------/                                           /--------//--------//--------//--------//--------/  
*                     |         |         |         |         |         |                                          |         |         |         |         |         | 
*                     |         |         |         |         |         |                                          |         |         |         |         |         | 
*                     \--------\\--------\\--------\\--------\/--------//--------/   /--------//--------/          \--------\\--------\\--------\\--------\\--------\  
*                                                             |         |         |  |         |         |                                                             
*                                                             |         |         |  |         |         |                                                             
*                                                             \--------\/--------/   /--------/\--------\                                                              
*                                                                       |         |  |         |                                                                       
*                                                                       |         |  |         |                                                                       
*                                                   /--------//--------//--------/   /--------//--------//--------/                                                    
*                                                   |         |         |         |  |         |         |         |                                                   
*                                                   |         |         |         |  |         |         |         |                                                   
*                                                   \--------\\--------\\--------\   \--------\\--------\\--------\                                                    
*                                                                                                                                                                      
* 
**/
[SMLY]=KEYMAP(
//left half
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                              KC_TRNS, KC_TRNS, 
                                                     KC_TRNS, 
                                       KC_TRNS, KC_TRNS, KC_TRNS, 
    //right half
    M(SM_KISS), M(SM_HEART), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, M(SM_FROWN), M(SM_SAD), M(SM_CRY), KC_TRNS, KC_TRNS, KC_TRNS, 
           M(SM_SMIRK), M(SM_SMILE), M(SM_LAUGH), KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, 
    KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS),
/**
* Layer: NUMB
* /-----//-----//-----//-----//-----//-----//-----/          /-----//-----//-----//-----//-----//-----//-----/         
* |      |      |      |      |      |      |      |         |      | F6   | F7   | F8   | F9   | F10  | F11  |        
* |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |        
* /-----//-----//-----//-----//-----//-----//-----/          /-----//-----//-----//-----//-----//-----//-----/         
* |      |      |      | UP   |      |      |      |         |      | /    | 7    | 8    | 9    | *    | F12  |        
* |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |        
* /-----//-----//-----//-----//-----//-----/\-----\          \-----\/-----//-----//-----//-----//-----//-----/         
* |      |      | LEFT | DOWN | RIGHT|      |                       | /    | 4    | 5    | 6    | +    | -    |        
* |      |      |      |      |      |      |                       |      |      |      |      |      |      |        
* /-----//-----//-----//-----//-----//-----//-----/          /-----//-----//-----//-----//-----//-----//-----/         
* |      |      |      |      |      |      |      |         |      | %    | 1    | 2    | 3    |      |      |        
* |      |      |      |      |      |      |      |         |      |      |      |      |      |      |      |        
* \-----\\-----\\-----\\-----\\-----\\-----\\-----\          \-----\\-----\\-----\\-----\\-----\\-----\\-----\         
*                                                                                                                      
*                                                                                                                      
*               /-----//-----//-----//-----//-----/                               /-----//-----//-----//-----//-----/  
*               |      |      |      |      |      |                              | 0    | .    | ,    | =    |      | 
*               |      |      |      |      |      |                              |      |      |      |      |      | 
*               \-----\\-----\\-----\\-----\/-----//-----/   /-----//-----/       \-----\\-----\\-----\\-----\\-----\  
*                                           |      |      |  |      |      |                                           
*                                           |      |      |  |      |      |                                           
*                                           \-----\/-----/   /-----/\-----\                                            
*                                                  |      |  |      |                                                  
*                                                  |      |  |      |                                                  
*                                    /-----//-----//-----/   /-----//-----//-----/                                     
*                                    |      |      |      |  |      |      |      |                                    
*                                    |      |      |      |  |      |      |      |                                    
*                                    \-----\\-----\\-----\   \-----\\-----\\-----\                                     
*                                                                                                                      
* 
**/
[NUMB]=KEYMAP(
//left half
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                              KC_TRNS, KC_TRNS, 
                                                     KC_TRNS, 
                                       KC_TRNS, KC_TRNS, KC_TRNS, 
    //right half
    KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
    KC_TRNS, DE_OSX_SLSH, KC_7, KC_8, KC_9, DE_OSX_ASTR, KC_F12, 
           DE_OSX_SLSH, KC_4, KC_5, KC_6, DE_OSX_PLUS, DE_OSX_MINS, 
    KC_TRNS, DE_OSX_PERC, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, 
                         KC_0, KC_DOT, KC_COMM, DE_OSX_EQL, KC_TRNS, 
    KC_TRNS, KC_TRNS, 
    KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS),
/**
* Layer: EGOS
* /--------//--------//--------//--------//--------//--------//--------/             /--------//--------//--------//--------//--------//--------//--------/            
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* /--------//--------//--------//--------//--------//--------//--------/             /--------//--------//--------//--------//--------//--------//--------/            
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* /--------//--------//--------//--------//--------//--------/\--------\             \--------\/--------//--------//--------//--------//--------//--------/            
* | Shift   |         |         |         |         |         |                                |         |         |         |         |         |         |           
* |         |         |         |         |         |         |                                |         |         |         |         |         |         |           
* /--------//--------//--------//--------//--------//--------//--------/             /--------//--------//--------//--------//--------//--------//--------/            
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* |         |         |         |         |         |         |         |            |         |         |         |         |         |         |         |           
* \--------\\--------\\--------\\--------\\--------\\--------\\--------\             \--------\\--------\\--------\\--------\\--------\\--------\\--------\            
*                                                                                                                                                                      
*                                                                                                                                                                      
*                     /--------//--------//--------//--------//--------/                                           /--------//--------//--------//--------//--------/  
*                     | Ctrl    |         |         |         |         |                                          |         |         |         | Toggle 5|         | 
*                     |         |         |         |         |         |                                          |         |         |         |         |         | 
*                     \--------\\--------\\--------\\--------\/--------//--------/   /--------//--------/          \--------\\--------\\--------\\--------\\--------\  
*                                                             | F1      | F2      |  |         |         |                                                             
*                                                             |         |         |  |         |         |                                                             
*                                                             \--------\/--------/   /--------/\--------\                                                              
*                                                                       | F3      |  |         |                                                                       
*                                                                       |         |  |         |                                                                       
*                                                   /--------//--------//--------/   /--------//--------//--------/                                                    
*                                                   | SPC     | Ctrl    | F4      |  |         |         |         |                                                   
*                                                   |         |         |         |  |         |         |         |                                                   
*                                                   \--------\\--------\\--------\   \--------\\--------\\--------\                                                    
*                                                                                                                                                                      
* 
**/
[EGOS]=KEYMAP(
//left half
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                  KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                              KC_F1, KC_F2, 
                                                     KC_F3, 
                                       KC_SPC, KC_LCTL, KC_F4, 
    //right half
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                         KC_TRNS, KC_TRNS, KC_TRNS, M(M_TOGGLE_5), KC_TRNS, 
    KC_TRNS, KC_TRNS, 
    KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
static uint16_t start;
switch(id) {
case SMLY_TOG_QUOT:
//Macro: SMLY_TOG_QUOT//-----------------------
if (record->event.pressed) {
			start = timer_read();
           layer_state ^= (1<<SMLY);
           layer_state &= (1<<SMLY);
			return MACRO_NONE; 		} else {
           layer_state ^= (1<<SMLY);
           layer_state &= (1<<SMLY);
			if (timer_elapsed(start) >150) {
				return MACRO_NONE;
			} else {
				return MACRO(DOWN(KC_LSFT),TYPE(DE_OSX_HASH),UP(KC_LSFT),END);
			}
		}

break;
case M_TOGGLE_5:
//Macro: M_TOGGLE_5//-----------------------
 if (record->event.pressed){
           layer_state ^= (1<<5);
           layer_state &= (1<<5);
        }

break;
case TGH_NUM:
//Macro: TGH_NUM//-----------------------
if (record->event.pressed){
         start = timer_read();
         layer_state ^=(1<<NUMB);
         layer_state &=(1<<NUMB);
 } else {
         if (timer_elapsed(start) > 150) {
                 layer_state^=(1<<NUMB);
                 layer_state&=(1<<NUMB);
         }
 }
return MACRO_NONE;

break;
case M_DE_OSX_PLUS_CTRLALT:
//Macro: M_DE_OSX_PLUS_CTRLALT//-----------------------
if (record->event.pressed) {
			start = timer_read();
			return MACRO(DOWN(KC_LCTRL),DOWN(KC_LALT),END);
		} else {
			if (timer_elapsed(start) >150) {
				return MACRO(U(LCTRL),U(LALT),END);
			} else {
				return MACRO(UP(KC_LCTRL),UP(KC_LALT),TYPE(KC_RBRC),END);
			}
		}

break;
case SM_KISS:
//Macro: SM_KISS//-----------------------
if (record->event.pressed) {
			return MACRO(DOWN(KC_LSFT),TYPE(KC_DOT),UP(KC_LSFT),TYPE(KC_SLSH),DOWN(KC_LSFT),TYPE(KC_RBRC),UP(KC_LSFT),END);
		}

break;
case SM_FROWN:
//Macro: SM_FROWN//-----------------------
if (record->event.pressed) {
			return MACRO(DOWN(KC_LSFT),TYPE(KC_DOT),UP(KC_LSFT),TYPE(KC_SLSH),DOWN(KC_LALT),TYPE(KC_8),UP(KC_LALT),END);
		}

break;
case SM_CRY:
//Macro: SM_CRY//-----------------------
if (record->event.pressed) {
			return MACRO(DOWN(KC_LSFT),TYPE(KC_COMM),UP(KC_LSFT),TYPE(KC_SLSH),DOWN(KC_LSFT),TYPE(KC_8),UP(KC_LSFT),END);
		}

break;
case SM_SMILE:
//Macro: SM_SMILE//-----------------------
if (record->event.pressed) {
			return MACRO(DOWN(KC_LSFT),TYPE(KC_DOT),UP(KC_LSFT),TYPE(KC_SLSH),DOWN(KC_LSFT),TYPE(KC_9),UP(KC_LSFT),END);
		}

break;
case SM_SMIRK:
//Macro: SM_SMIRK//-----------------------
if (record->event.pressed) {
			return MACRO(DOWN(KC_LSFT),TYPE(KC_COMM),UP(KC_LSFT),TYPE(KC_SLSH),DOWN(KC_LSFT),TYPE(KC_9),UP(KC_LSFT),END);
		}

break;
case M_Key_KC_BSLS_MODS:
//Macro: M_Key_KC_BSLS_MODS//-----------------------
if (record->event.pressed) {
			start = timer_read();
			return MACRO(DOWN(KC_LALT),DOWN(KC_LGUI),END);
		} else {
			if (timer_elapsed(start) >150) {
				return MACRO(U(LALT),U(LGUI),END);
			} else {
				return MACRO(UP(KC_LALT),UP(KC_LGUI),TYPE(KC_BSLS),END);
			}
		}

break;
case M_LGUI_SHFT:
//Macro: M_LGUI_SHFT//-----------------------
if (record->event.pressed){
			return MACRO(DOWN(KC_LGUI),DOWN(KC_LSFT),END);
		}else{
			return MACRO(UP(KC_LGUI),UP(KC_LSFT),END);
		}

break;
case SM_HEART:
//Macro: SM_HEART//-----------------------
if (record->event.pressed) {
			return MACRO(TYPE(KC_GRV),TYPE(KC_3),END);
		}

break;
case TOG_HLD_MDIA:
//Macro: TOG_HLD_MDIA//-----------------------
if (record->event.pressed){
         start = timer_read();
         layer_state ^=(1<<MDIA);
         layer_state &=(1<<MDIA);
 } else {
         if (timer_elapsed(start) > 150) {
                 layer_state^=(1<<MDIA);
                 layer_state&=(1<<MDIA);
         }
 }
return MACRO_NONE;

break;
case SM_LAUGH:
//Macro: SM_LAUGH//-----------------------
if (record->event.pressed) {
			return MACRO(DOWN(KC_LSFT),TYPE(KC_DOT),UP(KC_LSFT),TYPE(KC_SLSH),DOWN(KC_LSFT),TYPE(KC_D),UP(KC_LSFT),END);
		}

break;
case SM_SAD:
//Macro: SM_SAD//-----------------------
if (record->event.pressed) {
			return MACRO(DOWN(KC_LSFT),TYPE(KC_DOT),UP(KC_LSFT),TYPE(KC_SLSH),DOWN(KC_LSFT),TYPE(KC_8),UP(KC_LSFT),END);
		}

break;
case M_DE_OSX_CIRC_CTRLCMD:
//Macro: M_DE_OSX_CIRC_CTRLCMD//-----------------------
if (record->event.pressed) {
			start = timer_read();
			return MACRO(DOWN(KC_LCTRL),DOWN(KC_LGUI),END);
		} else {
			if (timer_elapsed(start) >150) {
				return MACRO(U(LCTRL),U(LGUI),END);
			} else {
				return MACRO(UP(KC_LCTRL),UP(KC_LGUI),TYPE(KC_NUBS),END);
			}
		}

break;
case M_MEH_SH_ACUT:
//Macro: M_MEH_SH_ACUT//-----------------------
if (record->event.pressed) {
			start = timer_read();
			return MACRO(DOWN(KC_LCTRL),DOWN(KC_LSFT),DOWN(KC_LALT),END);
		} else {
			if (timer_elapsed(start) >150) {
				return MACRO(U(LCTRL),U(LSFT),U(LALT),END);
			} else {
				return MACRO(UP(KC_LCTRL),UP(KC_LALT),TYPE(DE_OSX_ACUT),UP(KC_LSFT),END);
			}
		}

break;
}
return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_on();
  for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
    ergodox_led_all_set (i); 
    _delay_ms (5); 
  }
  _delay_ms(1000);
  for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
    ergodox_led_all_set (i); 
    _delay_ms (10);
  }
  ergodox_led_all_off();
  ergodox_led_all_set(LED_BRIGHTNESS_HI);

};

uint8_t is_exp=0;

LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

uint8_t layer = biton32(layer_state);


ergodox_board_led_off();
ergodox_right_led_1_off();
ergodox_right_led_2_off();
ergodox_right_led_3_off();
switch (layer) {

    case SYMB:
        ergodox_right_led_1_on();
        
        
    break;
    case MDIA:
        
        ergodox_right_led_2_on();
        
    break;
    case NUMB:
        
        
        ergodox_right_led_3_on();
    break;
    case EGOS:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
    break;
default:
// none
break;
}

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_J) {
      register_code(KC_LSFT);
      register_code(DE_DOT);
      unregister_code(KC_LSFT);
      unregister_code(DE_DOT);
      register_code(DE_MINS);
      unregister_code(DE_MINS);
      register_code(KC_LSFT);
      register_code(KC_9);
      unregister_code(KC_9);
      unregister_code(KC_LSFT);
    }

    SEQ_ONE_KEY(KC_H){
	register_code(KC_LSFT);
        register_code(DE_COMM); 
        unregister_code(DE_COMM); 
	unregister_code(KC_LSFT);
	register_code(DE_MINS);
	unregister_code(DE_MINS);
	register_code(KC_LSFT);
	register_code(KC_9);
	unregister_code(KC_9);
	unregister_code(KC_LSFT);
    }	

    SEQ_TWO_KEYS (KC_V,KC_E) {
	blinkRight();
      SEND_STRING (QMK_KEYBOARD " " QMK_KEYMAP " " QMK_VERSION " " KEYMAP_VERSION);
    }

    SEQ_ONE_KEY(KC_K){
	register_code(KC_LSFT);
	register_code(DE_DOT);
	unregister_code(DE_DOT);
 	unregister_code(KC_LSFT);
	register_code(DE_MINS);
	unregister_code(DE_MINS);
	register_code(KC_LSFT); 
	register_code(KC_D);
	unregister_code(KC_D);
	unregister_code(KC_LSFT);
    }

    SEQ_ONE_KEY(KC_U){
	register_code(KC_LSFT);
	register_code(DE_DOT);
	unregister_code(DE_DOT);
 	unregister_code(KC_LSFT);
	register_code(DE_MINS);
	unregister_code(DE_MINS);
	register_code(KC_LSFT); 
	register_code(KC_8);
	unregister_code(KC_8);
	unregister_code(KC_LSFT);
    }

    SEQ_ONE_KEY(KC_I){
	register_code(KC_LSFT);
	register_code(DE_COMM);
	unregister_code(DE_COMM);
 	unregister_code(KC_LSFT);
	register_code(DE_MINS);
	unregister_code(DE_MINS);
	register_code(KC_LSFT); 
	register_code(KC_8);
	unregister_code(KC_8);
	unregister_code(KC_LSFT);
    }

    SEQ_ONE_KEY(KC_Z){
	register_code(KC_LSFT);
	register_code(DE_COLN);
	unregister_code(DE_COLN);
	unregister_code(KC_LSFT);
	register_code(DE_MINS);
	unregister_code(DE_MINS);
	register_code(KC_LALT);
	register_code(KC_8);
	unregister_code(KC_8);
	unregister_code(KC_LALT);
    }

    SEQ_ONE_KEY(KC_6){
	register_code(KC_LSFT);
	register_code(DE_COLN);
	unregister_code(DE_COLN);
	unregister_code(KC_LSFT);
	register_code(DE_MINS);
	unregister_code(DE_MINS);
	register_code(KC_LSFT);
	register_code(DE_PLUS);
	unregister_code(DE_PLUS);
	unregister_code(KC_LSFT);
    }

    SEQ_ONE_KEY(KC_7){
	register_code(DE_OSX_LESS);
	unregister_code(DE_OSX_LESS);
	register_code(KC_3);
	unregister_code(KC_3);
   }
    SEQ_ONE_KEY(KC_5) {
	 layer_state ^=(1<<NUMB);
         layer_state &=(1<<NUMB);
      if (is_exp == 0) { 
       // default_layer_and (0); 
       // default_layer_or ((1 << NUMB));
        is_exp = 1; 
	blinkRight();
      } else {
        is_exp = 0; 
	blinkLeft();
      }    
    }
    SEQ_ONE_KEY(KC_4) {
	layer_state ^=(1<<MDIA);
	layer_state &=(1<<MDIA);
      if (is_exp == 0) { 
        is_exp = 1; 
	blinkRight();
      } else {
        is_exp = 0; 
	blinkLeft();
      }    
    }
  }

};

void blinkLeft() {

        ergodox_led_all_off ();
        ergodox_right_led_3_on ();
        _delay_ms (100);
        ergodox_right_led_2_on ();
        _delay_ms (100);
        ergodox_right_led_3_off ();
        ergodox_right_led_1_on ();
        _delay_ms (100);
        ergodox_right_led_2_off ();
        _delay_ms (100);
        ergodox_right_led_1_off ();
}

void blinkRight() {
        ergodox_led_all_off ();
        ergodox_right_led_1_on ();
        _delay_ms (100);
        ergodox_right_led_2_on ();
        _delay_ms (100);
        ergodox_right_led_1_off ();
        ergodox_right_led_3_on ();
        _delay_ms (100);
        ergodox_right_led_2_off ();
        _delay_ms (100);
        ergodox_right_led_3_off ();
}
