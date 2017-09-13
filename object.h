#pragma once

#include <memory>
#include "type.h"

class Object
{
public:
    Object()
    {

    }

    virtual ~Object()
    {

    }
    template <typename T>
    T* cast()
    {
        return dynamic_cast<T*>(this);
    }

    virtual Type type()
    {
        return Type::None;
    }

    virtual std::shared_ptr<Object> copy()
    {
        return std::shared_ptr(new Object);
    }
};