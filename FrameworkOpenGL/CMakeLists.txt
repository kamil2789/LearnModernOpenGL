cmake_minimum_required(VERSION 3.18)

project(FrameworkOpenGL VERSION 1.0)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/GlfwConfig.cpp
    src/GlfwWindowManager.cpp
    src/GladConfig.cpp
    src/ShaderFileReader.cpp
    src/ShaderProgram.cpp
    src/Triangle.cpp
    src/ColoredTriangle.cpp
    src/TexturedReactangle.cpp
    ${CMAKE_SOURCE_DIR}/Externals/glad/src/glad.c
)

add_dependencies(${PROJECT_NAME} glfw)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Result/libglfw3.a)

if (MSVC)
    target_link_libraries(${PROJECT_NAME} opengl32.lib)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Result/glfw3.lib)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/Externals/glfw/include
    ${CMAKE_SOURCE_DIR}/Externals/glad/include
    ${CMAKE_SOURCE_DIR}/Externals/stbImage
)

add_custom_command(TARGET FrameworkOpenGL PRE_BUILD
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/framework_pre_build.py)

add_custom_command(TARGET FrameworkOpenGL POST_BUILD
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/framework_post_build.py)