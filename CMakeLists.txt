cmake_minimum_required(VERSION 3.18)

project(LearnModernOpenGL VERSION 1.0)

add_subdirectory(Externals/googletest)
add_subdirectory(Externals/glfw)
add_subdirectory(FrameworkOpenGL)
#add_subdirectory(Tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
