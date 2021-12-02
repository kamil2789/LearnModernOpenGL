#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GlfwConfig.h"
#include "GlfwWindowManager.h"
#include "GladConfig.h"

int main()
{
    GlfwConfig glfwConfig{};
    glfwConfig.setDefaultWindowOptions();

    GlfwWindowManager windowManager{1200, 600, "LearnOpenGL"};
    windowManager.setContextCurrent();

    GladConfig gladConfig{};

    glViewport(0, 0, 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

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