#pragma once
#include <string>
#include <map>

class ShaderFileReader
{
public:
    ShaderFileReader() = delete;
    ShaderFileReader(const ShaderFileReader&) = delete;
    ShaderFileReader& operator=(const ShaderFileReader&) = delete;

    static std::string readSrcFromFile(const std::string& filename);

private:
    enum class ShaderType
    {
        Vertex,
        Fragment,
        Unknown
    };

    static const std::map<std::string, ShaderType> extensions;
    static const std::map<ShaderType, std::string> paths;
    static const std::string shadersPath;
    static ShaderType determineShaderType(const std::string& filename);
};