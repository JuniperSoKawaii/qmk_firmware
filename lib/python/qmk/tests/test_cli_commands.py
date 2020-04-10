import subprocess
from qmk.commands import run


def check_subcommand(command, *args):
    cmd = ['bin/qmk', command] + list(args)
    return run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)


def test_cformat():
    result = check_subcommand('cformat', 'quantum/matrix.c')
    assert result.returncode == 0


def test_compile():
    assert check_subcommand('compile', '-kb', 'handwired/onekey/pytest', '-km', 'default').returncode == 0


def test_flash():
    assert check_subcommand('flash', '-b').returncode == 1
    assert check_subcommand('flash').returncode == 1


def test_config():
    result = check_subcommand('config')
    assert result.returncode == 0
    assert 'general.color' in result.stdout


def test_kle2json():
    assert check_subcommand('kle2json', 'kle.txt', '-f').returncode == 0


def test_doctor():
    result = check_subcommand('doctor', '-n')
    assert result.returncode == 0
    assert 'QMK Doctor is checking your environment.' in result.stderr
    assert 'QMK is ready to go' in result.stderr


def test_hello():
    result = check_subcommand('hello')
    assert result.returncode == 0
    assert 'Hello,' in result.stderr


def test_pyformat():
    result = check_subcommand('pyformat')
    assert result.returncode == 0
    assert 'Successfully formatted the python code' in result.stderr


def test_list_keyboards():
    result = check_subcommand('list-keyboards')
    assert result.returncode == 0
    # check to see if a known keyboard is returned
    # this will fail if handwired/onekey/pytest is removed
    assert 'handwired/onekey/pytest' in result.stdout


# list-keymaps CLI tests
def test_list_keymaps_short():
    # check short arg format
    result = check_subcommand('list-keymaps', '-kb', 'handwired/onekey/pytest')
    assert result.returncode == 0
    assert 'default' and 'test' in result.stdout


def test_list_keymaps_long():
    # check long arg format
    result = check_subcommand('list-keymaps', '--keyboard', 'handwired/onekey/pytest')
    assert result.returncode == 0
    assert 'default' and 'test' in result.stdout


def test_list_keymaps_kb_only():
    # check keyboard param
    result = check_subcommand('list-keymaps', '-kb', 'niu_mini')
    assert result.returncode == 0
    assert 'default' in result.stdout


def test_list_keymaps_vendor_kb():
    # check vendor/keyboard param
    result = check_subcommand('list-keymaps', '-kb', 'ai03/lunar')
    assert result.returncode == 0
    assert 'default' and 'via' in result.stdout


def test_list_keymaps_vendor_kb_rev():
    # check vendor/keyboard/revision param
    result = check_subcommand('list-keymaps', '-kb', 'kbdfans/kbd67/mkiirgb/v2')
    assert result.returncode == 0
    assert 'default' and 'kemmeldev' in result.stdout


def test_list_keymaps_no_such_keyboard():
    # check keyboard does not exist
    result = check_subcommand('list-keymaps', '-kb', 'thiskeyboard/does/not/exist')
    assert result.returncode == 0
    assert 'does not exist' in result.stdout
