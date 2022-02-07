#include <stdexcept>
#include <GLFW/glfw3.h>

#include "GlfwConfig.h"

GlfwConfig::GlfwConfig()
{
    if (glfwInit() == GLFW_FALSE)
    {
        throw std::runtime_error{"GLFW init internal error"};
    }
}

void GlfwConfig::setDefaultWindowOptions() const
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GlfwConfig::~GlfwConfig()
{
    glfwTerminate();
}
