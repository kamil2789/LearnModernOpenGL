#include "EndToEndTests.h"

#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GlfwConfig.h"
#include "GlfwWindowManager.h"
#include "GladConfig.h"
#include "ShaderFileReader.h"
#include "ShaderProgram.h"
#include "Triangle.h"
#include "TexturedReactangle.h"
#include "TextureObject.h"

bool EndToEndTest::TexturedReactangleTest()
{
    GlfwConfig glfwConfig{};
    glfwConfig.setDefaultWindowOptions();

    GlfwWindowManager windowManager{800, 600, "LearnOpenGL"};
    windowManager.setContextCurrent();

    GladConfig gladConfig{};

    glViewport(0, 0, 800, 600);

    ShaderProgram textureShader{
        ShaderFileReader::readSrcFromFile("simpleTexture.vert"),
        ShaderFileReader::readSrcFromFile("simpleTexture.frag")
    };

    textureShader.compile();

    std::array<float, 32> vertices = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f
    };

    std::array<unsigned int, 6> indices = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    TexturedReactangle texturedReactangle{vertices, indices};
    texturedReactangle.init();

    TextureObject textureCrate{"textures/container.jpg"};
    textureCrate.init();

    //main program loop
    while(windowManager.isRunningWindow())
    {
        windowManager.processInput();
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);

        textureShader.run();
        textureCrate.bind();
        texturedReactangle.draw();

        windowManager.swapWindowBuffer();
        glfwPollEvents();
    }

    return true;
}