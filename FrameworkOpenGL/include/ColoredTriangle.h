#pragma once
#include <array>
#include "ISolidObject.h"

/* Prototype, temporary class */

class ColoredTriangle : public ISolidObject
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