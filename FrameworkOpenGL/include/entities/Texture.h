#pragma once
#include <string>

class Texture
{
public:
    Texture(const std::string& file);
    ~Texture();
    void setScalingOptions(unsigned int minFilter, unsigned int maxFilter) const;

    void init();
    void bind();

private:
    unsigned int texture;
    const std::string file;
};