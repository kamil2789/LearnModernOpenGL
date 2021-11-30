import os
import shutil
from pathlib import Path


BUILD_DIR = Path(os.getcwd()).parent.resolve()
RESULT_PATH = BUILD_DIR / "Result"
TESTS = BUILD_DIR / "Tests/Debug/Tests.exe"


def copy_unit_tests():
    shutil.copy(TESTS, RESULT_PATH)


def main():
    copy_unit_tests()


main()
