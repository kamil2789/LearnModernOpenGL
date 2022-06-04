#pragma once
#include <array>
#include "Object.h"

class ColoredTriangle : public Object
{
public:
    ColoredTriangle(const std::array<float, 18>& vertices);
    ~ColoredTriangle() override;

    void init() override;
    void draw() override;

private:
    unsigned int VBO;
    unsigned int VAO;
    std::array<float, 18> vertices;
};