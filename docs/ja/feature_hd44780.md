# HD44780 LCD ディスプレイ

これは Peter Fleuryの LCD ライブラリの統合です。このページは基本について説明します。[詳細なドキュメントについてはこのページをご覧ください](http://homepage.hispeed.ch/peterfleury/doxygen/avr-gcc-libraries/group__pfleury__lcd.html)

HD44780 ディスプレイのサポートを有効にするには、キーボードの`rules.mk`の`HD44780_ENABLE`フラグをyesに設定します。

## 設定

ディスプレイで使用されるピンと、キーボードの`config.h`の行と列の数を設定する必要があります。


HD44780のラベルが付いたセクションのコメントを外し、必要に応じてパラメータを変更します。
````
/*
 * HD44780 LCD ディスプレイ設定
 */

#define LCD_LINES           2     //< ディスプレイの表示行数
#define LCD_DISP_LENGTH    16     //< ディスプレイの行ごとの表示文字数
#define LCD_IO_MODE      1            //< 0: メモリ マップ モード 1: IO ポートモード
#if LCD_IO_MODE
#define LCD_PORT         PORTB        //< LCD行のためのポート
#define LCD_DATA0_PORT   LCD_PORT     //< 4ビット データビット 0 のポート
#define LCD_DATA1_PORT   LCD_PORT     //< 4ビット データビット 1 のポート
#define LCD_DATA2_PORT   LCD_PORT     //< 4ビット データビット 2 のポート
#define LCD_DATA3_PORT   LCD_PORT     //< 4ビット データビット 3 のポート
#define LCD_DATA0_PIN    4            //< 4ビット データビット 0 のピン
#define LCD_DATA1_PIN    5            //< 4ビット データビット 1 のピン
#define LCD_DATA2_PIN    6            //< 4ビット データビット 2 のピン
#define LCD_DATA3_PIN    7            //< 4ビット データビット 3 のピン
#define LCD_RS_PORT      LCD_PORT     //< RSラインのためのポート
#define LCD_RS_PIN       3            //< RSラインのためのピン
#define LCD_RW_PORT      LCD_PORT     //< RWラインのためのポート
#define LCD_RW_PIN       2            //< RWラインのためのピン
#define LCD_E_PORT       LCD_PORT     //< Enableラインのためのポート
#define LCD_E_PIN        1            //< Enableラインのためのピン
#endif
````

他のプロパティを設定する必要がある場合は、それらを`quantum/hd44780.h`からコピーし、それらを`config.h`に設定することができます。

## 使用法

ディスプレイを初期化するには、以下のパラメータの1つを使って`lcd_init()`を呼び出します:
````
LCD_DISP_OFF             : ディスプレイ オフ
LCD_DISP_ON              : ディスプレイ オン、カーソル オフ
LCD_DISP_ON_CURSOR       : ディスプレイ オン、カーソル オン
LCD_DISP_ON_CURSOR_BLINK : ディスプレイ オン、点滅時にカーソル
````
これはキーボード `matrix_init_kb` あるいはキーマップ `matrix_init_user`で行うのが最適です。
使用前にディスプレイをクリアすることをお勧めします。
そのためには、`lcd_clrsrc()`を呼びます。

ディスプレイに何かを表示するには、最初に`lcd_gotoxy(column, line)`を呼びます。最初の行の先頭に移動するには、`lcd_gotoxy(0, 0)` を呼び出し、その後`lcd_puts("example string")`を使って文字列を出力します。

ディスプレイを制御することができるより多くのメソッドがあります。[詳細なドキュメントについてはリンクされたページをご覧ください](http://homepage.hispeed.ch/peterfleury/doxygen/avr-gcc-libraries/group__pfleury__lcd.html)
