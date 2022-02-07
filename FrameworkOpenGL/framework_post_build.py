import os
import shutil
from pathlib import Path
from termcolor import colored
import sys

FRAMEWORK_PATHS = {"linux": "FrameworkOpenGL/FrameworkOpenGL",
                   "win32": "FrameworkOpenGL/Debug/FrameworkOpenGL.exe"}

BUILD_DIR = Path(os.getcwd()).parent.resolve()
RESULT_PATH = BUILD_DIR / "Result"
SHADERS_DIR = BUILD_DIR.parent.resolve() / "FrameworkOpenGL/shaders"
TEXTURES_DIR = BUILD_DIR.parent.resolve() / "FrameworkOpenGL/textures"


def copy_framework_exec():
    FRAMEWORK = FRAMEWORK_PATHS[sys.platform]
    shutil.copy(FRAMEWORK, RESULT_PATH)


def copy_shaders():
    shutil.copytree(SHADERS_DIR, RESULT_PATH / "shaders")


def copy_textures():
    shutil.copytree(TEXTURES_DIR, RESULT_PATH / "textures")


def main():
    copy_framework_exec()
    copy_shaders()
    copy_textures()
    print(colored("Binaries and shaders have been copied", "green"))


main()
