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

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

    int width, height, nrChannels;

    unsigned char *data = stbi_load("textures/container.jpg", &width, &height, &nrChannels, 0);
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, texture);
    textureShader.run();

    //main program loop
    while(windowManager.isRunningWindow())
    {
        windowManager.processInput();
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);

        texturedReactangle.draw();

        windowManager.swapWindowBuffer();
        glfwPollEvents();
    }

    return true;
}