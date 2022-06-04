#include "EndToEndTests.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "config/GlfwConfig.h"
#include "config/GlfwWindowManager.h"
#include "config/GladConfig.h"
#include "entities/ShaderFileReader.h"
#include "entities/ShaderProgram.h"
#include "entities/ColoredTriangle.h"

bool EndToEndTest::ColoredTriangleTest()
{
    GlfwConfig glfwConfig{};
    glfwConfig.setDefaultWindowOptions();

    GlfwWindowManager windowManager{800, 600, "ColoredTriangle"};
    windowManager.setContextCurrent();

    GladConfig gladConfig{};

    glViewport(0, 0, 800, 600);

    ShaderProgram simpleTriangleShader{
        ShaderFileReader::readSrcFromFile("colorVertex.vert"),
        ShaderFileReader::readSrcFromFile("colorFragment.frag")
    };

    simpleTriangleShader.compile();
    simpleTriangleShader.run();

    std::array<float, 18> vertices = {
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    ColoredTriangle triangle{vertices};
    triangle.init();

    glClearColor(0.2f, 0.3f, 0.0f, 1.0f);

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

    return true;
}