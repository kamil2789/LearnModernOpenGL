#pragma once
#include <array>
#include "Object.h"

class Triangle : public Object
{
public:
    Triangle(const std::array<float, 9>& vertices);
    ~Triangle();

    void init() override;
    void draw() override;

private:
    unsigned int VBO;
    unsigned int VAO;
    std::array<float, 9> vertices;
};