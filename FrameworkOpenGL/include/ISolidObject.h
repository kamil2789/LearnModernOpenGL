#pragma once

class ISolidObject
{
public:
    virtual ~ISolidObject() = default;
    virtual void init() = 0;
    virtual void draw() = 0;
};