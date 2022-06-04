#pragma once
#include <string>

struct GLFWwindow;

class GlfwWindowManager
{
public:
    GlfwWindowManager(unsigned short width, unsigned short height, std::string name);
    ~GlfwWindowManager();

    void setContextCurrent() const;
    bool isRunningWindow() const;
    void processInput() const;
    void swapWindowBuffer() const;

private:
    unsigned short width;
    unsigned short height;
    std::string name;
    GLFWwindow* window;

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};