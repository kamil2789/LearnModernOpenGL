#include <array>
#include "Triangle.h"

#include <glad/glad.h>

Triangle::~Triangle()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

Triangle::Triangle(const std::array<float, 9>& vertices):
    vertices(vertices)
{}

void Triangle::init()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), reinterpret_cast<void*>(vertices.data()), GL_STATIC_DRAW);

    auto layout = 0;
    auto vecSize = 3;
    auto stride = 3 * sizeof(float);
    auto offset = nullptr;
    glVertexAttribPointer(layout, vecSize, GL_FLOAT, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); 
}

void Triangle::draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}