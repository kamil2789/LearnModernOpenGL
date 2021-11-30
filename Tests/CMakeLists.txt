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
add_dependencies(${PROJECT_NAME} gmock)

target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Result/gtestd.lib)
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/build/Result/gmockd.lib)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/Externals/googletest/googlemock/include
    ${CMAKE_SOURCE_DIR}/FrameworkOpenGL/include
)

add_custom_command(TARGET Tests PRE_BUILD
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/tests_pre_build.py)

add_custom_command(TARGET Tests POST_BUILD
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/tests_post_build.py)