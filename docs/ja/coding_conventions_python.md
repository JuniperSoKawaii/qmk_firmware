# コーディング規約 (Python)

私たちのスタイルの大部分は、物事をあまり目立たなくするために幾つかのローカルな変更を加えた PEP8 に従います。

* サポートされる全てのプラットフォームとの互換性のために、Python 3.5 を対象にしています。
* 4 (4) つのスペース (soft tabs) を使ってインデントします
* コメントを自由に使うことをお勧めします
   * それらを機能の説明をするストーリーと考えて下さい
   * それらを自由に使って特定の決定がされた理由を説明してください
   * 明白なコメントは書かないでください
   * コメントが明らかかどうかが分からない場合は、コメントを含めてください
* 全ての機能について便利な docstring を必要とします。
* 一般的に、行を折り返さないで、必要なだけ長くすることができます。行を折り返すことを選択した場合は、76列を超えて折り返さないでください。
* 私たちの慣習の幾つかは、Python使いでは無い人にコードベースをより身近にするために、pythonコミュニティに広まっているものとは競合しています。

# YAPF

コードをスタイルするために [yapf](https://github.com/google/yapf) を使うことができます。[setup.cfg](setup.cfg)に設定を提供します。

# Import

`import ...` vs `from ... import ...` をいつ使うかについての厳密なルールはありません。理解しやすさと保守性が究極の目的です。

一般的に、コードを短く理解しやすくするためにモジュールから特定の関数とクラス名をインポートすることを好みます。これにより、名前が曖昧になることがあります。そのような場合、代わりにモジュールをimportすることを好みます。互換性モジュールをインポートする時を除いて、インポートする時は "as" キーワードを避けるべきです。

インポートはモジュールごとに1行にする必要があります。標準的なpythonルール - システム、サードパーティ、ローカルを使ってインポート命令文をグループ化します。

`from foo import *`を使わないでください。代わりにインポートしたいオブジェクトのリストを指定するか、モジュール全体をインポートします。

## Import の例

良い:

```
from qmk import effects

effects.echo()
```

悪い:

```
from qmk.effects import echo

echo()  # echoがどこから来たのかが不明瞭です
```

良い:

```
from qmk.keymap import compile_firmware

compile_firmware()
```

良いですが、上の方がより良いです:

```
import qmk.keymap

qmk.keymap.compile_firmware()
```

# 命令文

行ごとに1つの命令文

許可されている場合(例えば `if foo: bar`)でも、2つの命令文を1行に結合しません。

# 命名

`module_name`, `package_name`, `ClassName`, `method_name`, `ExceptionName`, `function_name`, `GLOBAL_CONSTANT_NAME`, `global_var_name`, `instance_var_name`, `function_parameter_name`, `local_var_name`.

関数名、変数名 およびファイル名は説明的でなければなりません; 略語を避けます。特に、プロジェクト外の読み手に曖昧あるいは馴染みのない略語を使わず、単語内の文字を削除して略さないでください。

常に .py のファイル名の拡張子を使います。ダッシュを使わないでください。

## 避けるべき名前

* カウンタあるいはイテレータを除く1文字の名前try/except 命令文内で例外識別子として "e" を使うかもしれません。
* パッケージ/モジュール名内のダッシュ (-)
* __double_leading_and_trailing_underscore__ 名 (Pythonの予約語)

# Docstring

docstring との一貫性を維持するために、以下のガイドラインを設定しました。

* マークダウン形式の使用
* 常に少なくとも1つの改行を含む3つのダブルクォートのdocstringを使ってください: `"""\n"""`
* 最初の行は、関数が行うことの短い (< 70文字) 説明です。
* docstring で更に必要な場合は、説明と残りの間に空白行を置きます。
* 開始の3つのダブルクォートと同じインデントレベルでインデント行を始めます
* 以下で説明する形式を使って全ての関数の引数を文章化します
* Args:, Returns: および Raises: が存在する場合、それらは docstring の最後の3つの要素で、それぞれ空白行で区切られなければなりません。

## 簡単な docstring の例

```
def my_awesome_function():
    """Return the number of seconds since 1970 Jan 1 00:00 UTC.
    """
    return int(time.time())
```

## 複雑な docstring の例

```
def my_awesome_function():
    """Return the number of seconds since 1970 Jan 1 00:00 UTC.

    This function always returns an integer number of seconds.
    """
    return int(time.time())
```

## 関数引数の docstring の例

```
def my_awesome_function(start=None, offset=0):
    """Return the number of seconds since 1970 Jan 1 00:00 UTC.

    This function always returns an integer number of seconds.


    Args:
        start
            The time to start at instead of 1970 Jan 1 00:00 UTC

        offset
            Return an answer that has this number of seconds subtracted first

    Returns:
        An integer describing a number of seconds.

    Raises:
        ValueError
            When `start` or `offset` are not positive numbers
    """
    if start < 0 or offset < 0:
        raise ValueError('start and offset must be positive numbers.')

    if not start:
        start = time.time()

    return int(start - offset)
```

# 例外

例外は例外的な状況を処理するために使われます。フローの制御のために使われるべきではありません。これはPythonの "許しを求める。"という規範からの逸脱です。例外をキャッチする場合、異常な状況を処理する必要があります。

何らかの理由で全ての例外のキャッチを使う場合は、cli.logを使って例外とスタックトレースを記録する必要があります。

try/except ブロックをできるだけ短くします。多数のtry命令文が必要な場合は、コードを再構成する必要があるかもしれません。

# タプル

1項目のタプルを定義する場合、タプルを使用していることをが明らかになるように、常に末尾のカンマを含めます。暗黙的な1項目のタプルのアンパックに頼らないでください。曖昧ではないリストを使うことをお勧めします。

これは一般的に使用されるprintf形式の整形文字列を使う場合に、特に重要です。

# リストと辞書

シーケンス形式と末尾のカンマとを区別するためにYAPFを設定しました。末尾のカンマが省略されると、YAPFはシーケンスを1つの行として整形します。末尾のカンマが含まれている場合、YAPFはシーケンスを1行ごとに1つの項目で整形します。

通常1行に短い定義を保持することを好むべきです。読みやすさと保守性を向上させるために、後からではなく早めに複数の行を分割してください。

# 括弧

過度な括弧は避けますが、括弧を使ってコードを理解しやすくします。タプルを明示的に返すか、あるいは数式の一部である場合を除き、return命令文でそれらを使わないでください。

# 整形文字列

通常はprintf形式の整形文字列を好みます。例:

```
name = 'World'
print('Hello, %s!' % (name,))
```

このスタイルはログ モジュールで使われており、私たちはそれを広範囲で利用しており、一貫性を保つために他の場所で採用しています。It is also more familiar to C programmers, who are a big part of our casual audience.

付属のCLIモジュールは、パーセント (%) 演算子を使わずにこれらを使うことをサポートしています。詳細は、`cli.echo()` と様々な `cli.log` 関数 (例えば、`cli.log.info()`) を見てください。

# 内包表記とジェネレータ表記

内包表記とジェネレータの自由な使用を推奨しますが、あまりに複雑にしないでください。複雑さが必要な場合は、理解しやすい for ループで代替します。

# ラムダ

使っても問題ありませんが、おそらく避けるべきです。内包表記とジェネレータを使えば、ラムダの必要性は以前ほど強くありません。

# 条件式

変数の割り当てでは問題ありませんが、そうでなければ避けるべきです。

条件式はコードに沿ったif文です。例えば:

```
x = 1 if cond else 2
```

一般にこれらを関数の引数、シーケンス項目などとして使用することはお勧めできません。簡単に見過ごします。

# デフォルトの引数値

推奨されていますが、値は不変オブジェクトでなければなりません。

引数リストでデフォルト値を指定する場合は、その場で変更できないオブジェクトを指定するように常に注意してください。可変オブジェクトを使う場合は、変更は呼び出しの間で持続しますが、これは通常では必要ありません。それがあなたのやろうとしていることであっても、他の人にとっては混乱するもので理解を妨げます。

悪い:

```
def my_func(foo={}):
    pass
```

良い:

```
def my_func(foo=None):
    if not foo:
        foo = {}
```

# プロパティ

getterおよびsetter関数の代わりにプロパティを常に使います。

```
class Foo(object):
    def __init__(self):
        self._bar = None

    @property
    def bar(self):
        return self._bar

    @bar.setter
    def bar(self, bar):
        self._bar = bar
```

# True/False の評価

通常、等しいかを調べるのではなく、if文で暗黙的な True/False 評価を選択すべきです。

悪い:

```
if foo == True:
    pass

if bar == False:
    pass
```

良い:

```
if foo:
    pass

if not bar:
    pass
```

# デコレータ

適切な時に使ってください。理解に役立つ時を除き、あまりに多くの魔法を避けるようにしてください。

# スレッドとマルチプロセス

避けるべきです。これが必要な場合は、コードをマージする前に強力なケースを作成する必要があります。

# Power Features

Pythonは非常に柔軟な言語で、独自のメタクラス、バイトコードへのアクセス、その場でのコンパイル、動的な継承、オブジェクトの親の変更、インポート ハック、リフレクション、システム内部の変更など、多くの素晴らしい機能を提供します。

これらを使わないでください。

パフォーマンスは私たちにとって重要な関心ごとではなく、コードの理解可能性がそうです。私たちは、コードベースを1日か2日しか遊んでいない人が利用できるようにしたいです。これらの機能は一般的に理解のしやすいさを犠牲にするため、より高速あるはよりコンパクトなコードで容易に理解できるコードを使うことをお勧めします。

一部の標準ライブラリモジュールはこれらの手法を使っており、これらのモジュールを利用しても問題ありません。ただし、それらを使う時には、読みやすいさと理解のしやすさを忘れないでください。

# タイプのアノテーション コード

今のところ型のアノテーション システムを使っていないため、コードにアノテーションをつけないことをお勧めします。将来これを再検討するかもしれません。

# 関数の長さ

小さくて焦点のあった関数を好みます。

長い関数が時には適切であることを理解しているので、関数の長さには厳密な制限はありません。関数が約40行を超える場合は、プログラムの構造を損なわずに分割できるかどうかを検討してください。

今のところ長い関数が完全に機能するとしても、数か月でそれを変更する人が新しい挙動を追加するかもしれません。これにより見つけにくいバグが発生するかもしれません。関数を短くかつシンプルにすることで、他の人がコードを読んで修正しやすくします。

幾つかのコードで作業をすると、長く複雑な関数を見つけるかもしれません。Do not be intimidated by modifying existing code: if working with such a function proves to be difficult, you find that errors are hard to debug, or you want to use a piece of it in several different contexts, consider breaking up the function into smaller and more manageable pieces.

# FIXMEs

FIXMEs をコードに残しても構いません。なぜ？このコードを文章化しないままにするよりも、少なくとも考え抜く必要がある(あるいは混乱している)コードの部分を文章化するように人々を勇気づけるほうが良いです。

全ての FIXMEs は以下のように整形されるべきです:

```
FIXME(username): frob機能が完了したらこのコードを再検討してください。
```

...usernameはあなたのGitHubのユーザ名です。

# ユニット テスト

良いです。いつかはやるべきです。
