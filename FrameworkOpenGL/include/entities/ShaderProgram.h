#pragma once
#include <string>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();
    ShaderProgram(const std::string& vertexSrc, const std::string& fragmentSrc);
    ShaderProgram(const ShaderProgram&) = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;

    void setVertexSrc(const std::string& vertexSrc);
    void setFragmentSrc(const std::string& fragmentSrc);
    void setUniformVariable(const std::string& varName, float value) const;
    unsigned int getID() const;

    void compile();
    void run();

private:
    unsigned int shaderProgramID;
    std::string vertexSrc;
    std::string fragmentSrc;
    
    unsigned int compileShaderSrc(const std::string& srcCode, unsigned int type);
};