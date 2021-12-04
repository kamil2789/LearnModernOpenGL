import os
import shutil
from pathlib import Path
from termcolor import colored


BUILD_DIR = Path(os.getcwd()).parent.resolve()
RESULT_PATH = BUILD_DIR / "Result"
FRAMEWORK = BUILD_DIR / "FrameworkOpenGL/Debug/FrameworkOpenGL.exe"
SHADERS_DIR = BUILD_DIR.parent.resolve() / "FrameworkOpenGL/shaders"


def copy_framework_exec():
    shutil.copy(FRAMEWORK, RESULT_PATH)


def copy_shaders():
    shutil.copytree(SHADERS_DIR, RESULT_PATH / "shaders")


def main():
    copy_framework_exec()
    copy_shaders()
    print(colored("Binaries and shaders have been copied", "green"))


main()
