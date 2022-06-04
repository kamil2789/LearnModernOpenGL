#include <stdexcept>
#include <GLFW/glfw3.h>
#include "config/GlfwWindowManager.h"

GlfwWindowManager::GlfwWindowManager(unsigned short width, unsigned short height, std::string name):
    width(width),
    height(height),
    name(name)
{
    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        throw std::runtime_error{"GLFW create window internal error"};
    }

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

GlfwWindowManager::~GlfwWindowManager()
{
    if (window != nullptr)
    {
        glfwDestroyWindow(window);
    }
}

void GlfwWindowManager::setContextCurrent() const
{
    glfwMakeContextCurrent(window);
}

bool GlfwWindowManager::isRunningWindow() const
{
    return glfwWindowShouldClose(window) == 0 ? true : false;
}

void GlfwWindowManager::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void GlfwWindowManager::processInput() const
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void GlfwWindowManager::swapWindowBuffer() const
{
    glfwSwapBuffers(window);
}
