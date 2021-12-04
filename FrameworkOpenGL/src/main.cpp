#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GlfwConfig.h"
#include "GlfwWindowManager.h"
#include "GladConfig.h"
#include "ShaderFileReader.h"

int main()
{
    GlfwConfig glfwConfig{};
    glfwConfig.setDefaultWindowOptions();

    GlfwWindowManager windowManager{1200, 600, "LearnOpenGL"};
    windowManager.setContextCurrent();

    GladConfig gladConfig{};

    glViewport(0, 0, 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };


    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //kopiuje punkty do zbindowanego buffora
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    std::string sourceCode{ShaderFileReader::readSrcFromFile("simplestVertex.vert")};
    const GLchar* source = reinterpret_cast<const GLchar*>(sourceCode.c_str());
    glShaderSource(vertexShader, 1, &source, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    sourceCode = ShaderFileReader::readSrcFromFile("simplestFragment.frag");
    const GLchar* source2 = reinterpret_cast<const GLchar*>(sourceCode.c_str());
    glShaderSource(fragmentShader, 1, &source2, nullptr);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //main program loop
    while(windowManager.isRunningWindow())
    {
        windowManager.processInput();
        //rendering
        glClear(GL_COLOR_BUFFER_BIT);
        //rendering end
        windowManager.swapWindowBuffer();
        glfwPollEvents();
    }

    return 0;
}