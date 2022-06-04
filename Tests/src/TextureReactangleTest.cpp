#include "EndToEndTests.h"

#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "config/GlfwConfig.h"
#include "config/GlfwWindowManager.h"
#include "config/GladConfig.h"
#include "entities/ShaderFileReader.h"
#include "entities/ShaderProgram.h"
#include "entities/Triangle.h"
#include "entities/TexturedReactangle.h"
#include "entities/Texture.h"

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

    Texture textureCrate{"textures/container.jpg"};
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