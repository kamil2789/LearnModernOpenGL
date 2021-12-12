#pragma once
#include <array>

/* Prototype, temporary class */

class Triangle
{
public:
    Triangle(const std::array<float, 9>& vertices);
    ~Triangle();

    void init();
    void draw();

private:
    unsigned int VBO;
    unsigned int VAO;
    std::array<float, 9> vertices;
};