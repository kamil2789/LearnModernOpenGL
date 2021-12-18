# LearnModernOpenGL
## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
My second approach to learning openGL. I'm mostly learning graphics concepts and writing my own framework or wrapper around openGL.
	
## Technologies
Technologies used in the project:
* C++17
* Python3
* Cmake
* GoogleTest
* OpenGL
* GLFW
* GLAD
	
## Setup
To run this project, download repository and type commands:

```
$ git submodule init
$ git submodule update
$ mkdir build
$ cd build
```

### Build with MSVC
Currently, only MSCV build is supported.
From build directory:

#### Debug build
```
$ cmake ..
$ cmake --build .
```

All needed binaries, libs and files are copied into build/Result folder.
On every build, shaders files are copied again in case of any changes.
