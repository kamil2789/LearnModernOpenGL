import os
import shutil
from pathlib import Path


BUILD_DIR = Path(os.getcwd()).parent.resolve()
RESULT_PATH = BUILD_DIR / "Result"
FRAMEWORK = BUILD_DIR / "FrameworkOpenGL/Debug/FrameworkOpenGL.exe"


def copy_framework_exec():
    shutil.copy(FRAMEWORK, RESULT_PATH)


def main():
    copy_framework_exec()


main()
