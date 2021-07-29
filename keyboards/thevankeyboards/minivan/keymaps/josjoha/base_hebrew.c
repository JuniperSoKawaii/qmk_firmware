/*
 * License (GPL):
  
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

 * Author: © 2021 by Jos Boersema
 *
 */

// --------------------------------------v---------------------------------------
//                                 Configuration:
// --------------------------------------v---------------------------------------


// --------------------------------------^---------------------------------------
//            Below here no more comfortable configuration options.....
// --------------------------------------^---------------------------------------

        /*                            Redefine a layer in this file
         *
         * _Activate_ one or more of the below BASESFILE_LAYER_..., to redefine the layer
         * in this file. The version in ./keymap.c will be ignored. Keep in mind to use
         * transparent keys (_______) for “hold” layer switch keys on the BASE map, for
         * your new layer.
         */
// #define BASESFILE_LAYER_ACC 
// #define BASESFILE_LAYER_DRA 
// #define BASESFILE_LAYER_BON 
// #define BASESFILE_LAYER_PAD 
// #define BASESFILE_LAYER_MOV 
// #define BASESFILE_LAYER_RAR 
// #define BASESFILE_LAYER_FUN 

        /*  ⬇ */

    /* Layer _..._BASE: default BASE layer (Hebrew)
     *
     * - Dual use keys create a delay in the key (tap/hold keys), therefore
     *   space is not dual use (most used key), neither is hyphen.
     */ 

// Process user configuration wrt ‛Default’ or ‛Alternative’ spot for this layout.
# if   defined(BASE_HEBREW__DEF_BASE)
    [ _DEF_BASE ] = LAYOUT_redefined (
# elif defined(BASE_HEBREW__ALT_BASE)
    [ _ALT_BASE ] = LAYOUT_redefined (
# endif

/*
     Layer _..._BASE (LeTteRs, standard Hebrew as in Israel)
     ➡ This is a simple hebrew layout. Notice the letter ק is displaced from normal,
       to retain compatibility with Dvorak-English for ,<.>. There are no niqqud
       available, because it is far too many unique symbols in Unicode, and it is 
       rarely used.

                                                  | Right hand
         <pink2     <pinky<ring <middl<index<indx2| indx2>index>middl>ring> pinky>pinky2>   // Keys by finger
         -o-                                     <|>                                    ... //-o- BASE access
         Esc        '"    ,<    .>    ר     א     | ט     ו     ן     ם     פ          Bksp
         Tab+LCtl   ש     ד     ג     כ     ע     | י     ח     ל     ך     ף             ־
         LSht+_PAD  ז     ס     ב     ה     נ     | מ     צ     ת     ץ     ק     RSht+_FUN
             +_MOV⁵                               |                                   +_RAR⁶
     ---------------------------------------------------------------------------------------
     Left+LAlt Del;_ACC _..._NSY(_DRA)  Enter+_MOV| Space  _..._NSY(_DRA) LGUI    Right;_RAR 
               hold     hold₍₁,₂٭₎      hold      |        hold₍₁,₂٭₎             hold     // switch type
               hold₍₂₎  ^-┃-----------------------+--------^ ┃                          // ₁₎ both = _DRA
               ┗━━━_BON━━━╋┅───────────┄┄┄«or»┄┄┄─+─────────┅┛                          // ₂₎ both = _BON
     <1   ±    <2       <3              <4        | 4>     3>             2>   ±  1>    // Keys by number
          ^³                                                                   ^⁴   // Optional more keys
          …                                                                    …
     
     ₁) Dual hold for _DRA, single hold for _..._NSY. Marked by: ^--…--^
     ₂) Hold key “<2” with either٭ key “<3” or “3>” for _BON, single hold “<2” for _ACC. Marked: ┗━━…━━┛
     ³) 'South paw' hardware configuration 
     ⁴) 'Arrow' hardware configuration 
     ³ ⁴) There are two more optional hardware keys, to make it easier to compile for
          a 12x12x12x11 or 12x12x12x12 layouts.
     ⁵) Left Shift when pressed with another key. Medium long: to toggle _PAD. Long: toggle _MOV.
     ⁶) Right shift when pressed with another key. medium long: to toggle _FUN. Long: toggle _RAR.
*/
//
//      <pink2            , <pinky    , <ring     , <middl    , <indx     ,      <ind|, indx>     , inde>     , midd>     , ring>     , pink>     , pink2>        ,
//      -*!-              ,           ,           ,           ,           ,         <|,>          ,           ,           ,           ,           ,               ,
      //KC_ESC            , XP_HEB_AA , XP_HEB_AB , XP_HEB_AC , XP_HEB_AD , XP_HEB_AE , XP_HEB_AF , XP_HEB_AG , XP_HEB_AH , XP_HEB_AI , XP_HEB_AJ , KC_BSPC       ,
        KC_ESC            , KC_QUOT   , KC_COMM   , KC_DOT    , XP_HEB_AD , XP_HEB_AE , XP_HEB_AF , XP_HEB_AG , XP_HEB_AH , XP_HEB_AI , XP_HEB_AJ , KC_BSPC       ,
        LCTL_T ( KC_TAB ) , XP_HEB_BA , XP_HEB_BB , XP_HEB_BC , XP_HEB_BD , XP_HEB_BE , XP_HEB_BF , XP_HEB_BG , XP_HEB_BH , XP_HEB_BI , XP_HEB_BJ , XP_HEB_BK     ,
        CHOLTAP_LSHFT     , XP_HEB_CA , XP_HEB_CB , XP_HEB_CC , XP_HEB_CD , XP_HEB_CE , XP_HEB_CF , XP_HEB_CG , XP_HEB_CH , XP_HEB_CI , XP_HEB_CJ , CHOLTAP_RSHFT ,
//      -----------------------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) 

# ifdef TRANSMINIVAN_LEFTSIDE
                           , MO ( _PAD )
# endif

# ifdef MORE_KEY__COMMAND
                           , MORE_key1_BASE  
# endif

# ifdef SWITCH_HOLD_ACC_NSY 
                           , DUO_HOLD , CHOLTAP_ACCE 
# else
                           , CHOLTAP_ACCE , DUO_HOLD
# endif

                                                     , LEFTCENTER_THUMB

# ifdef TRANSMINIVAN_MIDLEFT
                                                     , TRANS_MIDLEFT
# endif

                                                                       , RIGHTCENTER_THUMB , DUO_HOLD , KC__YGUI

# ifdef TRANSMINIVAN_RIGHTSIDE
                                                                                                                 , MO ( _FUN )
# endif                                                                                    
                                                                                           
# ifdef MORE_KEY__ARROW                                                                    
                                                                                                                 , MORE_key2  
# endif                                                                                    
                                                                                           
                                                                                                                 , CHOLTAP_LAYR
//                         ,              ,          ,               <|,>                  ,          ,          ,
//      <1           ±  ±  , <2           , <3       , <4             |, 4>                , 3>       , 2>       , ±  ±  1>

                      ),

        /* ⬆⬇ */

    /* Layer _..._NSY: Numbers and symbols.
     *          Off hand Number input (-.Bksp ent (shft)tab).
     */
    // KC_TILD does not work there, because of a limitation with shifted keys (nov 2019).

// Process user configuration wrt ‛Default’ or ‛Alternative’ spot for this layout.
# if   defined(BASE_HEBREW__DEF_BASE)
    [ _DEF_NSY ] = LAYOUT_redefined (
# elif defined(BASE_HEBREW__ALT_BASE)
    [ _ALT_NSY ] = LAYOUT_redefined (
# endif

/*
     Layer _..._NSY (Numbers and SYmbols)
     ➡ The brace type symbols are *not* reversed as on standard hebrew boards (I find it confusing).
    
     <pink2   <pinky<ring <middl<index<indx2| indx2>index>middl>ring>pin>pink2>
              -*-                          <|>                                  //(toggle) Access on _FUN
     BASE     !     @     #     $     %     | ^     &     *     (    )       Del
     Tab+LCtl 1!    2@    3#    4$    5%    | 6^    7&    8*    9(   0)  `~+RCtl
     -+LSht   [{    ]}    /?    \|    =+    | +     |     ?     {     }   ~+RSht 
     ---------------------------------------------------------------------------
     Left+LAlt ___   ___   Ent  | .   ___   LGUI  Right+RAlt
                     -*-       <|>    -*-                                         //(hold) Access on _..._BASE
       <1   ±  <2    <3    <4   | 4>  3>    2>  ± 1>  
            …                                   …
*/
//
//
//      <pink2             , <pinky  , <ring   , <middl  , <index  , <indx2 |, indx2>  , index>  , middl>  , ring>   , pinky>  , pink2>             ,
//                         , -*-     ,         ,         ,         ,       <|,>        ,         ,         ,         ,         ,                    ,
        CTO_BASE           , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL             ,
        LCTL_T ( KC_TAB )  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , RCTL_T ( KC_GRV )  ,
        LSFT_DASH          , KC_LBRC , KC_RBRC , KC_SLSH , KC_BSLS , KC_EQL  , KC_PLUS , KC_PIPE , KC_QUES , KC_LCBR , KC_RCBR , RSFT_TILDE         ,
//      ---------------------------------------------------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) 

# ifdef TRANSMINIVAN_LEFTSIDE
                           , TRANS_LEFT
# endif

# ifdef MORE_KEY__COMMAND
                           , MORE_key1
# endif

                           , _______ , _______ , KC_ENT

# ifdef TRANSMINIVAN_MIDLEFT
                                               , TRANS_MIDLEFT
# endif
                                                        , KC_DOT , DUO_HOLD , KC__YGUI

# ifdef TRANSMINIVAN_RIGHTSIDE
                                                                                       , TRANS_RIGHT
# endif

# ifdef MORE_KEY__ARROW
                                                                                       , MORE_key2  
# endif                                     

                                                                                       , RALT_T ( KC_RIGHT )
//                         ,         , -*-     ,      <|,>       , -*-      ,          ,
//      <1           ±  ±  , <2      , <3      , <4    |, 4>     , 3>       , 2>       , ±  ±  1>

                      ),


        /* ⬆⬇ */
