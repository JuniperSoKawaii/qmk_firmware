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

 * Author: (C) 2020 by Jos Boersema
 *
 */

/*

      Overview of Qwerty/Dvorak setting: goal, changes.

The goal is to maintain the exact regular Qwerty or Dvorak within the
10x10x10 rows available. The remainder (pinky right/up and 5th row of
standard layouts) is put on the numbers/symbols layer, which follows
neither standard layout. The key -_ in Dvorak and '" in Qwerty falls
on the 11th key on the third row, and is also replicated as standard.

This is implemented by copying both letters and numbers layers to this
file, even though the number/symbols layer changes only one key, to
make the code simpler (for people without programming experience too).
Otherwise two keys on the letters/symbols would have a special #define,
which might cause someone without enough programming experience to get
lost. (As I understand it, these files are supposed to be editable by the
keyboard user, who is not necessarily a programmer in any way).

Because this version of the layout does not have a 'descramble' mode, 
the associated 'descramble' unicode layers have been cut out (see
unicode_macros.c), and the key going to 'descramble half' no longer
does that. It only goes to 'descramble full' which is hereby replaced
with a standard Dvorak layer.

With that set, the only thing that changes is the placement of basic
keycodes such as KC_A, KC_B, etc. All modifiers, layer switching and
keys like space, enter, tab, delete, backspace, GUI, etc, are left
as they where. 

All the changes are effectuated using the pre-processor.

There are a potential few things that could be optimized for a Qwerty
user, which are not automatically done. On the layer _PAD, there are
no changes, hence '-' in _PAD is not on the same spot it is on _NSY.
If such optimization is wanted, the user has to do it by hand in _PAD.

*/

    /* Layer _LTR: Qwerty, normal BASE layer and 'default' layer
     *
     * - Dual use keys create a delay in the key (tap/hold keys), therefore
     *   space is not dual use (most ued key), neither is hyphen.
     */ 

    [ _LTR ] = LAYOUT_redefined (

/*
     Layer _LTR (LeTteRs). This is standard Qwerty (#define QWERTY_DVORAK set.)
                                             | Right hand
     <pink2    <pinky<ring <middl<index<indx2| indx2>index>middl>ring> pinky>pinky2>    // Keys by finger
     -o-                                    <|>                                    ... // -o- BASE access
     Esc       qQ    wW    eE    rR    tT    | yY    uU    iI    oO    pP         Bksp
     Tab+LCtl  aA    sS    dD    fF    gG    | hH    jJ    kK    lL    ;:           '"
     LSht+_PAD zZ    xX    cC    vV    bB    | nN    mM    ,<    .>    /?    RSht+_FUN   // _FUN _MOV tap
     -------------------------------------------------------------------------------
     Left+LAlt Del;_ACC _NSY(_DRA)  Enter+_MOV| Space  _NSY(_DRA) LGUI    Right;_RAR  // _XYZ is to layer
               hold     hold₍₂₎     hold      |        hold₍₂₎    hold    hold       // Layer switch type
                        ^---------------------+--------^                              // both hold = _DRA
     <1   ±    <2       <3          <4        | 4>     3>         2>   ±  1>            // Keys by number

*/
//
//      <pink2            , <pink, <ring, <midd, <indx, <ind|, indx>, inde>, midd>   , ring>  , pink>   , pink2>        ,
//      -*!-              ,      ,      ,      ,      ,    <|,>     ,      ,         ,        ,         ,               ,
        KC_ESC            , KC_Q , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I    , KC_O   , KC_P    , KC_BSPC       ,
        LCTL_T ( KC_TAB ) , KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K    , KC_L   , KC_SCLN , KC_QUOT       ,
        CHOLTAP_LSHFT     , KC_Z , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH , CHOLTAP_RSHFT ,
//      -----------------------------------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) J1_J2
#ifdef MORE_KEY__COMMAND
                                 , MORE_key1  
#endif
                                 , CHOLTAP_ACCE , DUO_HOLD , LT ( _MOV , KC_ENT ) , KC_SPC , DUO_HOLD , KC__YGUI
#ifdef MORE_KEY__ARROW
                                                                                                                 , MORE_key2  
#endif
                                                                                                                 , J3_J4 CHOLTAP_LAYR
//                               ,              ,          ,                    <|,>       ,          ,          ,
//      <1                 ±  ±  , <2           , <3       , <4                  |, 4>     , 3>       , 2>       , ±  ±  1>
                      ),

        /**/

    /* Layer _DDL: (standard Dvorak) 
     *
     */

    [ _DDL ] = LAYOUT_redefined (

/*
     Layer _DDL This is a standard Dvorak layer (#define QWERTY_DVORAK set.)
                                             | Right hand
     <pink2    <pinky<ring <middl<index<indx2| indx2>index>middl>ring> pinky>pinky2> 
     -o-                                    <|>                                   ...  //(to) BASE access
     Esc       '"    ,<    .>    pP    yY    | fF    gG    cC    rR    lL         Bksp
     Tab+LCtl  aA    oO    eE    uU    iI    | dD    hH    tT    nN    sS           -_
     LSft+_PAD ;:    qQ    jJ    kK    xX    | bB    mM    wW    vV    zZ    RSft+_FUN   // _FUN _MOV tap
     -------------------------------------------------------------------------------
     Left+LAlt Del;_ACC _DDN(DRAW)  Enter+_MOV| Space  _DDN(DRAW) LGUI    Right;_RAR  // _XYZ is to layer
               hold     hold₍₂₎     hold      |        hold₍₂₎    hold    hold       // Layer switch type
                        ^---------------------+--------^                              // both hold = DRAW
     <1   ±    <2       <3          <4        | 4>     3>         2>   ±  1>            // Keys by number


 */
//                                                   
//
//      <pink2            , <pinky  , <ring   , <midd  , <indx, <ind|, indx>, inde>, midd>, ring>, pink>, pink2>        ,
//      -*-               ,         ,         ,        ,      ,    <|,>     ,      ,      ,      ,      , -!-           ,
        KC_ESC            , KC_QUOT , KC_COMM , KC_DOT , KC_P , KC_Y , KC_F , KC_G , KC_C , KC_R , KC_L , KC_BSPC       ,
        LCTL_T ( KC_TAB ) , KC_A    , KC_O    , KC_E   , KC_U , KC_I , KC_D , KC_H , KC_T , KC_N , KC_S , KC_MINS       ,
        CHOLTAP_LSHFT     , KC_SCLN , KC_Q    , KC_J   , KC_K , KC_X , KC_B , KC_M , KC_W , KC_V , KC_Z , CHOLTAP_RSHFT ,
//      -----------------------------------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) J1_J2 
#ifdef MORE_KEY__COMMAND
                                 , MORE_key1  
#endif
                                 , CHOLTAP_ACCE , DUO_HOLD , LT ( _MOV , KC_ENT ) , KC_SPC , DUO_HOLD , KC__YGUI
#ifdef MORE_KEY__ARROW
                                                                                                                 , MORE_key2  
#endif
                                                                                                                 , J3_J4 CHOLTAP_LAYR
//                               ,              ,          ,                    <|,>       ,          ,          ,
//      <1                 ±  ±  , <2           , <3       , <4                  |, 4>     , 3>       , 2>       , ±  ±  1>
                      ),

        /**/

    /* Layer _NSY: Numbers and symbols, to work with the Qwerty base layer above.
     *          Off hand Number input (-.Bksp ent (shft)tab).
     */
    // KC_TILD does not work there, because of a limitation with shifted keys (nov 2019).

    [ _NSY ] = LAYOUT_redefined (

/*
     Layer _NSY (Numbers and SYmbols). This fits the above Qwerty layer _LTR (#define QWERTY_DVORAK set.)
    
     <pink2   <pinky<ring <middl<index<indx2| indx2>index>middl>ring>pin>pink2>
              -*-                          <|>                                  //(toggle) Access on _FUN
     BASE     !     @     #     $     %     | ^     &     *     (    )      Bspc
     Tab+LCtl 1!    2@    3#    4$    5%    | 6^    7&    8*    9(   0)  `~+RCtl
     -+LSft   [{    ]}    -_    \|    =+    | +     |     _     {     }   `+RSft // limitation prevents ~
                          ^^                              ^  // Only differences with normal version _NSY
     -------------------------------------------------------
     Left+LAlt Del   ___   Ent  | .   ___   LGUI  Right+RAlt
                     -*-       <|>    -*-                                         //(hold) Access on _LTR
       <1   ±  <2    <3    <4   | 4>  3>    2>  ± 1>  
*/
//
//
//      <pink2             , <pinky  , <ring   , <middl  , <index  , <indx2 |, indx2>  , index>  , middl>  , ring>   , pinky>  , pink2>             ,
//                         , -*-     ,         ,         ,         ,       <|,>        ,         ,         ,         ,         ,                    ,
        CTO_BASE           , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC            ,
        LCTL_T ( KC_TAB )  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , RCTL_T ( KC_GRV )  , 
        LSFT_T ( KC_MINS ) , KC_LBRC , KC_RBRC , KC_MINS , KC_BSLS , KC_EQL  , KC_PLUS , KC_PIPE , KC_UNDS , KC_LCBR , KC_RCBR , RSFT_T ( KC_TILD ) ,  
//      ---------------------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) J1_J2 
#ifdef MORE_KEY__COMMAND
                                 , MORE_key1  
#endif
                                 , KC_DEL , DUO_HOLD , KC_ENT , KC_DOT , DUO_HOLD , KC__YGUI
#ifdef MORE_KEY__ARROW
                                                                                             , MORE_key2  
#endif
                                                                                             , J3_J4 RALT_T ( KC_RGHT )
//                               ,        , -*-      ,      <|,>       , -*-      ,          ,
//      <1                 ±  ±  , <2     , <3       , <4    |, 4>     , 3>       , 2>       , ±  ±  1>
                      ),

        /**/


    /* Layer _DDN: Numbers/Symbols for the Dvorak layer. Exactly the same as normal version 
     * (without #define QWERTY_DVORAK set) _NSY.
     *
     */
    // KC_TILD does not work there, because of a limitation with shifted keys (nov 2019).

    [ _DDN ] = LAYOUT_redefined (

/*
     Layer _DDN (Dvorak numbers/symbols). Fits above _DDL Dvorak (with #define QWERTY_DVORAK set.)
    
     <pink2   <pinky<ring <middl<index<indx2| indx2>index>middl>ring>pin>pink2>
              -*-                          <|>                                  //(toggle) Access on _FUN
     BASE     !     @     #     $     %     | ^     &     *     (    )      Bspc
     Tab+LCtl 1!    2@    3#    4$    5%    | 6^    7&    8*    9(   0)  `~+RCtl
     -+LSft   [{    ]}    /?    \|    =+    | +     |     ?     {     }   `+RSft // limitation prevents ~
     -------------------------------------------------------
     Left+LAlt Del   ___   Ent  | .   ___   LGUI  Right+RAlt
                     -*-       <|>    -*-                                         //(hold) Access on _LTR
       <1   ±  <2    <3    <4   | 4>  3>    2>  ± 1>  
*/
//
//
//      <pink2             , <pinky  , <ring   , <middl  , <index  , <indx2 |, indx2>  , index>  , middl>  , ring>   , pinky>  , pink2>             ,
//                         , -*-     ,         ,         ,         ,       <|,>        ,         ,         ,         ,         ,                    ,
        CTO_BASE           , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC            ,
        LCTL_T ( KC_TAB )  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , RCTL_T ( KC_GRV )  , 
        LSFT_T ( KC_MINS ) , KC_LBRC , KC_RBRC , KC_SLSH , KC_BSLS , KC_EQL  , KC_PLUS , KC_PIPE , KC_QUES , KC_LCBR , KC_RCBR , RSFT_T ( KC_TILD ) ,  
//      -------------------------------------------------------------------------------------------------
        LALT_T ( KC_LEFT ) J1_J2 
#ifdef MORE_KEY__COMMAND
                                 , MORE_key1  
#endif
                                 , KC_DEL , DUO_HOLD , KC_ENT , KC_DOT , DUO_HOLD , KC__YGUI
#ifdef MORE_KEY__ARROW
                                                                                             , MORE_key2  
#endif
                                                                                             , J3_J4 RALT_T ( KC_RGHT )
//                               ,        , -*-      ,      <|,>       , -*-      ,          ,
//      <1                       , <2     , <3       , <4    |, 4>     , 3>       , 2>       ,       1>
                      ),

        /**/
