#include "EndToEndTests.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "config/GlfwConfig.h"
#include "config/GlfwWindowManager.h"
#include "config/GladConfig.h"
#include "entities/ShaderFileReader.h"
#include "entities/ShaderProgram.h"
#include "entities/Triangle.h"

bool EndToEndTest::GradientTriangleWithUniformTest()
{
    GlfwConfig glfwConfig{};
    glfwConfig.setDefaultWindowOptions();

    GlfwWindowManager windowManager{800, 600, "GradientTriangleWithUniformTest"};
    windowManager.setContextCurrent();

    GladConfig gladConfig{};

    glViewport(0, 0, 800, 600);

    ShaderProgram simpleTriangleShader{
        ShaderFileReader::readSrcFromFile("simplestVertex.vert"),
        ShaderFileReader::readSrcFromFile("uniformFragment.frag")
    };

    simpleTriangleShader.compile();
    simpleTriangleShader.run();

    std::array<float, 9> vertices = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };

    Triangle triangle{vertices};
    triangle.init();

    glClearColor(0.2f, 0.3f, 0.0f, 1.0f);

    while(windowManager.isRunningWindow())
    {
        windowManager.processInput();
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);

        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;

        simpleTriangleShader.setUniformVariable("ActualColor", greenValue);
        triangle.draw();

        //rendering end
        windowManager.swapWindowBuffer();
        glfwPollEvents();
    }

    return true;
}