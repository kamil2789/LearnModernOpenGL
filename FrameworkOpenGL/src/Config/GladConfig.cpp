#include <stdexcept>
#include "config/GladConfig.h"

GladConfig::GladConfig()
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        throw std::runtime_error{"Failed to initialize GLAD"};
    }
}