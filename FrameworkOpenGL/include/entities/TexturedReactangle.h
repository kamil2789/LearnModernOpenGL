#pragma once
#include <array>
#include "Object.h"

class TexturedReactangle : public Object
{
public:
    TexturedReactangle(const std::array<float, 32>& vertices, const std::array<unsigned int, 6>& indices);
    ~TexturedReactangle();

    void init() override;
    void draw() override;

private:
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    std::array<float, 32> vertices;
    std::array<unsigned int, 6> indices;
};