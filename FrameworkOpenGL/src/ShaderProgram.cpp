#include <string>
#include <stdexcept>
#include "ShaderProgram.h"

#include <glad/glad.h>

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(shaderProgramID);
}

ShaderProgram::ShaderProgram()
{
    shaderProgramID = glCreateProgram();
    if (shaderProgramID == 0)
    {
        throw std::runtime_error{"GL create program internal error"};
    }
}

ShaderProgram::ShaderProgram(const std::string& vertexSrc, const std::string& fragmentSrc):
    ShaderProgram()
{
    this->vertexSrc = vertexSrc;
    this->fragmentSrc = fragmentSrc;
}

void ShaderProgram::setVertexSrc(const std::string& vertexSrc)
{
    this->vertexSrc = vertexSrc;
}

void ShaderProgram::setFragmentSrc(const std::string& fragmentSrc)
{
    this->fragmentSrc = fragmentSrc;
}

unsigned int ShaderProgram::getID() const
{
    return shaderProgramID;
}

void ShaderProgram::compile()
{
    auto vertexShader = compileShaderSrc(vertexSrc, GL_VERTEX_SHADER);
    auto fragmentShader = compileShaderSrc(fragmentSrc, GL_FRAGMENT_SHADER);

    glAttachShader(shaderProgramID, vertexShader);
    glAttachShader(shaderProgramID, fragmentShader);
    glLinkProgram(shaderProgramID);

    int success;
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shaderProgramID, 512, nullptr, infoLog);
        throw std::runtime_error{"Shader program link error " + std::string{infoLog}};
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

unsigned int ShaderProgram::compileShaderSrc(const std::string& srcCode, unsigned int type)
{
    unsigned int shader{glCreateShader(type)};
    if (shader == 0)
    {
        throw std::runtime_error{"GL create shader internal error"}; 
    }

    const GLchar* source = reinterpret_cast<const GLchar*>(srcCode.c_str());
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        throw std::runtime_error{"Vertex shader compilation error " + std::string{infoLog}};
    }

    return shader;
}

void ShaderProgram::run()
{
    glUseProgram(shaderProgramID);
}