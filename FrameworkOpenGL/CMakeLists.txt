cmake_minimum_required(VERSION 3.18)

project(FrameworkOpenGL VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    ${CMAKE_SOURCE_DIR}/Externals/glad/src/glad.c
)

add_dependencies(${PROJECT_NAME} glfw)

target_link_libraries(${PROJECT_NAME} opengl32.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Externals/glfw/src/Debug/glfw3.lib)


target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/Externals/glfw/include
    ${CMAKE_SOURCE_DIR}/Externals/glad/include
)