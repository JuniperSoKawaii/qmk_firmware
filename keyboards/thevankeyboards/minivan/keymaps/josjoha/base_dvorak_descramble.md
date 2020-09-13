# Minifan layout

Compiled for: Dvorak² 
=====================

This file details the compile version `#define BASE_DVORAK_DESCRAMBLE__ALT_BASE`
which has a special version of Dvorak so that you can
type Dvorak on a computer *already* set to do Dvorak layout re-mapping.

This can be useful on for example a laptop, for which the build-in
keyboard should to be in Dvorak. An external keyboard which normally
types Dvorak, will not yield Dvorak in this case, unless you reconfigure
something on your computer.

With the regular Dvorak and *this* Dvorak² keymap, you can type both
normally in Dvorak, plus by activating its ‛descramble’ mode (see
Chapter below) you can directly type on a computer already set to Dvorak.

Dvorak² keymaps
---------------

──────────Dvorak───────────────

![Minivan layout Image BASEdef-alt](http://socialism.nl/misc/minivan/minivan_base_layer_dvorak_va.jpg)
Layer: `..._BASE`

![Minivan layout Image NSYdef-alt](http://socialism.nl/misc/minivan/minivan_nsy_layer_dvorak_va.jpg)
Layer: `..._NSY`

──────────in common────────────

(…) 

For more about the other layers, see ➡ ![readme.md](./readme.md) ⬅

![Minivan illustration Overview layers by key, Dvorak](http://socialism.nl/misc/minivan/minivan-all-layers-clear-visualization-by-key_dvorak_2000_vb.jpg)

Layers (text)
=============
 
          Layer _ALT_BASE (Dvorak descramble mode for letters)
                                                  | Right hand
          <pink2    <pinky<ring <middl<index<indx2| indx2>index>middl>ring> pinky>pinky2>    // Keys by finger
          -o-                                    <|>                                    ... // -o- BASE access
          Esc       '"    ,<    .>    pP    yY    | fF    gG    cC    rR    lL         Bksp
          Tab+LCtl  aA    oO    eE    uU    iI    | dD    hH    tT    nN    sS           -_
          LSht+_PAD ;:    qQ    jJ    kK    xX    | bB    mM    wW    vV    zZ    RSht+_FUN   // _FUN _MOV tap
              +_MOV⁵                              |
     ---------------------------------------------------------------------------------------
     Left+LAlt Del;_ACC _ALT_NSY(_DRA)  Enter+_MOV| Space  _ALT_NSY(_DRA) LGUI    Right;_RAR 
               hold     hold₍₁,₂٭₎      hold      |        hold₍₁,₂٭₎             hold     // switch type
               hold₍₂₎  ^-┃-----------------------+--------^ ┃                          // ₁₎ both = _DRA
               ┗━━━━━━━━━━╋┅───────────┄┄┄«or»┄┄┄─+─────────┅┛                          // ₂₎ both = _BON
     <1   ±    <2       <3              <4        | 4>     3>             2>   ±  1>    // Keys by number
          ^³                                                                   ^⁴   // Optional more keys

     This layer input results in the same as normal Dvorak if computer side Dvorak remapping is occuring.
     Only shown what changes:

              '"    ,<    .>    pP    yY    | fF    gG    cC    rR    lL                 // row 4, result
                    oO    eE    uU    iI    | dD    hH    tT    nN    sS   -_            // row 3, result
              ;:    qQ    jJ    kK    xX    | bB          wW    vV    zZ                 // row 2, result
     -------------------------------------------------------------------------------
                        _ALT_NSY                           _ALT_NSY                              // row 1, result

     (Keys for 'aA', '\|' and 'mM' are the same in Dvorak and Qwerty.)

- - -
    
     Layer _ALT_NSY (Dvorak descramble mode for numbers-symbols)
    
     <pink2   <pinky<ring <middl<index<indx2| indx2>index>middl>ring>pin>pink2>
              -*-                          <|>                                  //(toggle) Access on _FUN
     BASE     !     @     #     $     %     | ^     &     *     (    )       Del
     Tab+LCtl 1!    2@    3#    4$    5%    | 6^    7&    8*    9(   0)  `~+RCtl
     -+LSht   -_    =+    [{    \|    ]}    | }     |     {     _     +  `~+RSht            // row 2, raw
     ---------------------------------------------------------------------------
                 Left+LAlt ___   ___   Ent  | .   ___   LGUI  Right+RAlt
                                 -*-       <|>    -*-                        //(hold) Access on _DEF_BASE
                   <1   ±  <2    <3    <4   | 4>  3>    2>  ± 1>  

     This layer input results in the same as regular Dvorak _..._NSY layer, if computer side Dvorak remapping
     is occuring. Only shown what changes:

              [{    ]}    /?           =+   |   +         ?     {     }                  // row 2, result

- - -

Special feature: 'Descramble' mode
==================================

![Minivan descramble Dvorak](http://socialism.nl/misc/minivan/minivan_descramble.jpg)

  This is an option to take care of typing normally on a computer already
  set to Dvorak ('descramble' mode.)  

  Activation: go to `_RAR` layer, than touch what is space bar on the BASE layer
  (the key just right from the middle on the first row). This cycles through the modes.

      ⮚ When the left led is white: normal mode.
      ⮚ Right led white: full descramble mode (Linux descrambled Unicode input).
      ⮚ Middle led white: half descramble mode, with normal Unicode input system.

  With the middle led set to white, you can take advantage of a Unicode
  input mode that works on your system, if it is the same when the
  computer is set to Dvorak or not (see `_RAR` layer for Unicode input
  encoding selection). (The speed measurement middle led use is overridden
  by the `_RAR` layer.) This more or less means there is one more Unicode
  encoding option than already standard in QMK: 'descrambled' version for 
  Linux (Shift-Control-U HEX) encoding, for use on a computer *already* set to
  Dvorak.

  To test it, (in Debian/Linux) go to a terminal in X and type (normal user)

        > setxkbmap -layout us -variant dvorak

  Undo:

        > setxkbmap -layout us

  Unicode on Windos may require to install something special.


Key associations
----------------
Key placement associations between layers for Dvorak.

![Minivan layout Image associations](http://socialism.nl/misc/minivan/minivan-relationships_dvorak-descramble_1500_va.jpg)

