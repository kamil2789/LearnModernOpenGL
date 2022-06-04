#pragma once

class Object
{
public:
    virtual ~Object() = default;
    virtual void init() = 0;
    virtual void draw() = 0;
};