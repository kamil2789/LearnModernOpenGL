#pragma once

class Object;
class Action
{
public:
    Action{Object& object};
    virtual void execute() = 0;
};