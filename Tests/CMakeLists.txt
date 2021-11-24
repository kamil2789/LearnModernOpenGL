cmake_minimum_required(VERSION 3.18)

project(Tests VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/exampleTest.cpp
    #FrameworkOpenGL project
    #${CMAKE_SOURCE_DIR}/FrameworkOpenGL/src/
)

add_dependencies(${PROJECT_NAME} gtest)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/lib/Debug/gtest.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/lib/Debug/gmock.lib)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googlemock/include
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/include
)