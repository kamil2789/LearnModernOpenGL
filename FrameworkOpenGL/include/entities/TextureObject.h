#pragma once

class TextureObject
{
public:
    TextureObject(const std::string& file);
    ~TextureObject();
    void setScalingOptions(unsigned int minFilter, unsigned int maxFilter) const;

    void init();
    void bind();

private:
    unsigned int texture;
    const std::string file;
};