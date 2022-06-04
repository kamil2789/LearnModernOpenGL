#pragma once
#include <optional>

#include "entities/Texture.h"
#include "entities/Vertices.h"
#include "entities/ShaderProgram.h"

class Object
{
public:
    virtual ~Object() = default;
    virtual void init() = 0;
    virtual void draw() = 0;

    std::optional<Vertices> vertices;
    std::optional<Texture> texture;
    std::optional<ShaderProgram> shaderProgram;
};