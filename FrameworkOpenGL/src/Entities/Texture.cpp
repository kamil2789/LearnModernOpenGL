#include <string>
#include <stdexcept>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "entities/Texture.h"

Texture::Texture(const std::string& file):
    file(file)
{
    glGenTextures(1, &texture);
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture);
}

void Texture::init()
{
    int width, height, nrChannels;

    unsigned char *data = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);

    if (data == nullptr)
    {
        throw std::runtime_error{"Error during load image to application"};
    }

    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, texture);
}