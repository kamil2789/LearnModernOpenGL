import os
import shutil
from pathlib import Path

BUILD_DIR = Path(os.getcwd()).parent.resolve()
RESULT_PATH = BUILD_DIR / "Result"
GLFW = BUILD_DIR / "Externals/glfw/src/Debug/glfw3.lib"


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
    shutil.copy(GLFW, RESULT_PATH)


def main():
    prepare_empty_build_result_dir()
    copy_glfw_libs()


main()
