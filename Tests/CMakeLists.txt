cmake_minimum_required(VERSION 3.18)

project(Tests VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/ShaderFileReaderTest.cpp
    src/GradientTriangleWithUniformTest.cpp
    src/ColoredTriangleTest.cpp
    src/EndToEnd.cpp
    src/TextureReactangleTest.cpp
    #FrameworkOpenGL project
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/ShaderFileReader.cpp
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/GladConfig.cpp
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/ShaderProgram.cpp
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/Triangle.cpp
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/GlfwWindowManager.cpp
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/GlfwConfig.cpp
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/ColoredTriangle.cpp
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/TexturedReactangle.cpp
    #External
    ${CMAKE_SOURCE_DIR}/Externals/glad/src/glad.c
)

add_dependencies(${PROJECT_NAME} gtest)
add_dependencies(${PROJECT_NAME} gmock)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Result/gtestd.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Result/gmockd.lib)
target_link_libraries(${PROJECT_NAME} opengl32.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Result/glfw3.lib)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googlemock/include
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/include
    ${CMAKE_SOURCE_DIR}/Externals/glfw/include
    ${CMAKE_SOURCE_DIR}/Externals/glad/include
    ${CMAKE_SOURCE_DIR}/Externals/stbImage
)

add_custom_command(TARGET Tests PRE_BUILD
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/tests_pre_build.py)

add_custom_command(TARGET Tests POST_BUILD
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/tests_post_build.py)