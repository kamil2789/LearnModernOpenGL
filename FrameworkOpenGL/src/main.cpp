#include <iostream>
#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GlfwConfig.h"
#include "GlfwWindowManager.h"
#include "GladConfig.h"
#include "ShaderFileReader.h"
#include "ShaderProgram.h"
#include "Triangle.h"

int main()
{
    GlfwConfig glfwConfig{};
    glfwConfig.setDefaultWindowOptions();

    GlfwWindowManager windowManager{800, 600, "LearnOpenGL"};
    windowManager.setContextCurrent();

    GladConfig gladConfig{};

    glViewport(0, 0, 800, 600);

    ShaderProgram simpleTriangleShader{
        ShaderFileReader::readSrcFromFile("simplestVertex.vert"),
        ShaderFileReader::readSrcFromFile("simplestFragment.frag")
    };

    simpleTriangleShader.compile();

    std::array<float, 9> vertices = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    Triangle triangle{vertices};
    triangle.init();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    simpleTriangleShader.run();

    //main program loop
    while(windowManager.isRunningWindow())
    {
        windowManager.processInput();
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);

        triangle.draw();

        //rendering end
        windowManager.swapWindowBuffer();
        glfwPollEvents();
    }

    return 0;
}