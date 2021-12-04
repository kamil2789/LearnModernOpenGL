#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "ShaderFileReader.h"

const std::map<std::string, ShaderFileReader::ShaderType> ShaderFileReader::extensions {
        std::make_pair(".frag", ShaderType::Fragment),
        std::make_pair(".vert", ShaderType::Vertex)
};

const std::map<ShaderFileReader::ShaderType, std::string> ShaderFileReader::paths {
        std::make_pair(ShaderType::Fragment, "fragment/"),
        std::make_pair(ShaderType::Vertex, "vertex/"),
        std::make_pair(ShaderType::Unknown, "")
};

const std::string ShaderFileReader::shadersPath{"shaders/"};


std::string ShaderFileReader::readSrcFromFile(const std::string& filename)
{
    auto folderName = paths.at(determineShaderType(filename));
    if (folderName.empty())
    {
        throw std::invalid_argument{"Invalid file extension"};
    }

    std::ifstream file;
    auto path = shadersPath + folderName + filename;
    file.open(path);
    if (!file)
    {
        throw std::invalid_argument{"File could not be opened. Path: " + path};
    }

    std::stringstream result;
    result << file.rdbuf();
    file.close();

    return result.str();
}

ShaderFileReader::ShaderType ShaderFileReader::determineShaderType(const std::string& filename)
{
    if (auto found = filename.rfind("."); found != std::string::npos)
    {
        try
        {
            return extensions.at(filename.substr(found));
        }
        catch(const std::out_of_range&)
        {
            return ShaderType::Unknown;
        }
    }
    else
    {
        return ShaderType::Unknown;
    }
}