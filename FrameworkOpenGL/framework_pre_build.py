import os
import shutil
from pathlib import Path
from termcolor import colored
import sys


GLFW_PATHS = {"linux": "../Externals/glfw/src/libglfw3.a",
             "win32": "Externals/glfw/src/Debug/glfw3.lib"}

BUILD_DIR = Path(os.getcwd()).parent.resolve()
RESULT_PATH = BUILD_DIR / "Result"


def prepare_empty_build_result_dir():
    try:
        shutil.rmtree(RESULT_PATH)
    except FileNotFoundError as error:
        print("Directory not found, continue")
    except OSError as error:
        print(f"Unexpected error {error.strerror}")

    os.mkdir(RESULT_PATH)
    print("Build result folder created")


def copy_glfw_libs():
    GLFW = GLFW_PATHS[sys.platform]
    shutil.copy(GLFW, RESULT_PATH)


def main():
    print(colored("Start pre build script for the Framework", "blue"))
    prepare_empty_build_result_dir()
    copy_glfw_libs()
    print(colored("Result folder has been prepared", "green"))


main()
