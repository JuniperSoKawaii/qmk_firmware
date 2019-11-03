# QMK CLI 開発

このドキュメントは、新しい`qmk`サブコマンドを書きたい開発者のために役立つ情報が含まれています。

# 概要

QMK CLI はgitで有名になったサブコマンドパターンを使って動作します。メインの`qmk`スクリプトは単に環境をセットアップし、実行する正しいエントリポイントを選択するためにあります。各サブコマンドは、何らかのアクションを実行しシェルのリターンコードをまたはNoneを返すエントリーポイント(`@cli.subcommand()`で修飾されます)を備えた自己完結型のモジュールです。

# サブコマンド

[MILC](https://github.com/clueboard/milc) は、引数の解析、設定、ログ、およびほかの多くの機能を処理するために使用する CLI フレームワーク `qmk`です。グルーコードを書くために時間を無駄にすることなく、ツールの作成に集中できます。

ローカルCLI内のサブコマンドは、常に`qmk_firmware/lib/python/qmk/cli`で見つかります。

サブコマンドの例を見てみましょう。これは`lib/python/qmk/cli/hello.py`です:

```python
"""QMK Python Hello World

This is an example QMK CLI script.
"""
from milc import cli


@cli.argument('-n', '--name', default='World', help='Name to greet.')
@cli.subcommand('QMK Hello World.')
def hello(cli):
    """Log a friendly greeting.
    """
    cli.log.info('Hello, %s!', cli.config.hello.name)
```

最初に`milc`から`cli` をインポートします。これが、ユーザとやり取りをし、スクリプトの挙動を制御する方法です。コマンドライン フラグ `--name` を定義するために、`@cli.argument()`を使います。これは、ユーザが引数を指定する必要が無いように設定することができる`hello.name` (そして対応する`user.name`) という名前の設定変数も作成します。`cli.subcommand()` デコレータは、この関数をサブコマンドとして指定します。サブコマンドの名前は関数の名前から取られます。

関数の中に入ると、典型的な "Hello, World!" プログラムが見つかります。基礎となる[Logger Object](https://docs.python.org/3.5/library/logging.html#logger-objects)にアクセスするために`cli.log`を使います。この挙動はユーザが制御できます。またユーザが`cli.config.hello.name`として指定した名前の値にアクセスします。`cli.config.hello.name`の値は、ユーザが指定した `--name` 引数を調べることで決定されます。指定されていない場合、`qmk.ini` 設定ファイルの中の値が使われ、どちらも指定されていない場合は`cli.argument()` デコレータで指定されたデフォルトが代用されます。

# ユーザのやり取り

MILC とQMK CLI にはユーザとやり取りするための幾つかの便利なツールがあります。これらの標準ツールを使うと、テキストに色を付けて操作し易くし、ユーザはその情報をいつどうのように表示および保存するかを制御することができます。

## テキストの表示

サブコマンド内でテキストを出力するための2つの主なメソッドがあります- `cli.log` and `cli.echo()`。それらは似た方法で動作しますが、ほとんどの一般的な目的の出力には`cli.log.info()`を使うことをお勧めします。

特別なトークンを使用してテキストを色付けし、プログラムの出力を理解しやすくすることができます。以下の[テキストの色付け](#colorizing-text)を見てください。

これらの両方メソッドは pythonの [printf style string format operations](https://docs.python.org/3.5/library/stdtypes.html#old-string-formatting).を使って組み込みの文字列整形をサポートします。テキスト文字列内で`%s` と `%d` のようなトークンを使い、引数として値を渡すことができます。例として、上記の Hello、World プログラムを見てください。

書式演算子 (`%`) を直接使わないでください、常に値を引数として渡します。

### ログ (`cli.log`)

`cli.log` オブジェクトは[Logger Object](https://docs.python.org/3.5/library/logging.html#logger-objects)へのアクセスを与えます。各ログレベル(またはターミナルがunicodeをサポートしない場合はログレベル名)にユーザに素敵な絵文字を表示するようにログ出力を設定しました。このようにして、何か問題が発生した時に最も重要なメッセージを一目で判断することができます。

デフォルトのログレベルは `INFO`です。ユーザが `qmk -v <subcommand>` を実行すると、デフォルトのログレベルは `DEBUG` に設定されます。

| 機能 | 絵文字 |
|----------|-------|
| cli.log.critical | `{bg_red}{fg_white}¬_¬{style_reset_all}` |
| cli.log.error | `{fg_red}☒{style_reset_all}` |
| cli.log.warning | `{fg_yellow}⚠{style_reset_all}` |
| cli.log.info | `{fg_blue}Ψ{style_reset_all}` |
| cli.log.debug | `{fg_cyan}☐{style_reset_all}` |
| cli.log.notset | `{style_reset_all}¯\\_(o_o)_/¯` |

### 出力 (`cli.echo`)

場合によっては単にログシステムの外部でテキストを出力する必要があります。これは、固定データを出力したり、ログに記録してはいけない何かを書きだす場合に適しています。ほとんどの場合、`cli.echo`よりも`cli.log.info()`を好むはずです。

### テキストの色付け

テキスト内に色トークンを含めることで、テキストの出力を色付けすることができます。色を使って情報を使えるのではなく、強調表示します。ユーザは色を無効にできることを覚えておいてください。そうすればサブコマンドは引き続ぎ使えるはずです。

背景色を設定するのは、あなたがやっていることに不可欠ではない限り、通常は避けるべきです。ターミナルの色に関しては、ユーザは多くの好みを持つため、黒と白の両方の背景に対してうまく機能する色を選択する必要があることに覚えておいてください。

'fg' という接頭辞の付いた色は、前景(テキスト)の色に影響します。'bg' という接頭辞の付いた色は、背景色に影響します。

| 色 | 背景 | 拡張背景 | 前景 | 拡張前景 |
|-------|------------|---------------------|------------|--------------------|
| 黒 | {bg_black} | {bg_lightblack_ex} | {fg_black} | {fg_lightblack_ex} |
| 青 | {bg_blue} | {bg_lightblue_ex} | {fg_blue} | {fg_lightblue_ex} |
| 藍色 | {bg_cyan} | {bg_lightcyan_ex} | {fg_cyan} | {fg_lightcyan_ex} |
| 緑 | {bg_green} | {bg_lightgreen_ex} | {fg_green} | {fg_lightgreen_ex} |
| 赤紫 | {bg_magenta} | {bg_lightmagenta_ex} | {fg_magenta} | {fg_lightmagenta_ex} |
| 赤 | {bg_red} | {bg_lightred_ex} | {fg_red} | {fg_lightred_ex} |
| 白 | {bg_white} | {bg_lightwhite_ex} | {fg_white} | {fg_lightwhite_ex} |
| 黄色 | {bg_yellow} | {bg_lightyellow_ex} | {fg_yellow} | {fg_lightyellow_ex} |

ANSI出力の挙動を変更するために使うことができる制御シーケンスもあります。

| 色シーケンス | 説明 |
|-------------------|-------------|
| {style_bright} | テキストを明るくする |
| {style_dim} | テキストを暗くする |
| {style_normal} | テキストを通常にする (`{style_bright}` または `{style_dim}`のどちらでもない) |
| {style_reset_all} | 全てのテキストの属性をデフォルトに再設定する(これは自動的に全ての文字列の最後に自動的に追加されます。) |
| {bg_reset} | 背景色をユーザのデフォルトに再設定します。 |
| {fg_reset} | 背景色をユーザのデフォルトに再設定します。 |

# 引数と設定

QMK は引数の解析と設定の詳細を処理します。新しい引数を追加すると、サブコマンドの名前と引数の長い名前に基づいて設定ツリーに自動的に組み込まれます。attribute-style アクセス (`cli.config.<subcommand>.<argument>`) あるいは dictionary-style アクセス (`cli.config['<subcommand>']['<argument>']`) を使って、`cli.config`内のこの設定にアクセスすることができます。

内部では、QMK は設定を買う脳するために [ConfigParser](https://docs.python.org/3/library/configparser.html) を使います。これにより、人間が編集可能な方法で設定を表す簡単で分かり易い方法を提供します。ConfigParserが通常持たない幾つかの機能を提供するために、この設定へのアクセスをラップしました。

## 設定値の読み込み

通常期待される全ての方法で `cli.config`とやり取りすることができます。例えば、`qmk compile` コマンドは`cli.config.compile.keyboard`からキーボード名を取得します。値がコマンドライン、環境変数あるいは設定ファイルからきたものであるかどうかを知る必要はありません。

繰り返しもサポートされます:

```
cli.config のセクション:
    cli.config[section] のキー:
        cli.log.info('%s.%s: %s', section, key, cli.config[section][key])
```

## 設定値の設定

通常の方法で設定値を設定することができます。

辞書形式:

```
cli.config['<section>']['<key>'] = <value>
```

属性形式:

```
cli.config.<section>.<key> = <value>
```

## 設定値の削除

通常の方法で設定値を削除することができます。

辞書形式:

```
del(cli.config['<section>']['<key>'])
```

属性形式:

```
del(cli.config.<section>.<key>)
```

## 設定ファイルの書き方

設定は変更された時に書き出されません。ほとんどのコマンドでこれをする必要はありません。ユーザに`qmk config`を使って設定を慎重に変更させることをお勧めします。

設定を書き出すために`cli.save_config()`を使うことができます。

## 設定からの引数の除外

一部の引数は設定ファイルに伝播しないでください。これらは引数を作成した時に`arg_only=True` を追加することで除外することができます。

例:

```
@cli.argument('-o', '--output', arg_only=True, help='File to write to')
@cli.argument('filename', arg_only=True, help='Configurator JSON file')
@cli.subcommand('Create a keymap.c from a QMK Configurator export.')
def json_keymap(cli):
    pass
```

`cli.args`を使ってのみこれらの引数にアクセスすることができます。例えば:

```
cli.log.info('Reading from %s and writing to %s', cli.args.filename, cli.args.output)
```
