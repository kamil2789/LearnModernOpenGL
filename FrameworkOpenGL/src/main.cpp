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

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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
        0.0f, 0.5f, 0.0f,
    };

    std::array<float, 9> vertices2 = {
        -0.9f, -0.9f, 0.0f,
        0.0f, -0.9f, 0.0f,
        -0.5f, -0.6f, 0.0f
    };

    Triangle triangle{vertices};
    triangle.init();

    Triangle triangle2{vertices2};
    triangle2.init();

    auto actualColor = 0.0f;
    bool isUp = true;
    auto ratio = 0.005f;

    simpleTriangleShader.run();

    //main program loop
    while(windowManager.isRunningWindow())
    {
        windowManager.processInput();
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);

        triangle.draw();
        triangle2.draw();

        glClearColor(0.2f, 0.3f, actualColor, 1.0f);
        if (isUp)
        {
            actualColor += ratio;
        }
        else
        {
            actualColor -= ratio;
        }

        if (actualColor > 0.9f && isUp)
        {
            isUp = false;
        }
        else if (actualColor < 0.02f && isUp == false)
        {
            isUp = true;
        }
        //rendering end
        windowManager.swapWindowBuffer();
        glfwPollEvents();
    }

    return 0;
}