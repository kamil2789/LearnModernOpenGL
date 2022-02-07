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

### Linux build
```
cmake ..
```

### Troubleshooting
```
Could NOT find X11 (missing: X11_X11_INCLUDE_PATH X11_X11_LIB)
Solution:
sudo yum install libX11-devel
```
```
No CMAKE_CXX_COMPILER could be found
Solution:
yum group install c-development
```
```
Missing packages for GLFW:
sudo yum install libXrandr-devel
sudo yum install libXinerama-devel
sudo yum install libXcursor-devel
sudo yum install libXi-devel
```
```
fatal error: GL/gl.h: No such file or directory
Solution:
sudo yum install mesa-libGL-devel 
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
