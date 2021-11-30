import os
import shutil
from pathlib import Path


BUILD_DIR = Path(os.getcwd()).parent.resolve()
RESULT_PATH = BUILD_DIR / "Result"
GTEST = BUILD_DIR / "lib/Debug/gtestd.lib"
GMOCK = BUILD_DIR / "lib/Debug/gmockd.lib"


def copy_googletest_libs():
    shutil.copy(GTEST, RESULT_PATH)
    shutil.copy(GMOCK, RESULT_PATH)


def main():
    copy_googletest_libs()


main()
