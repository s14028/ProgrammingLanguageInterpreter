#pragma once

#include <memory>

#include "Type.h"
class Object
{
	Type type;
public:
    Object(Type type)
    {
			
    }

    virtual ~Object()
    {

    }

    virtual std::shared_ptr<Object> copy();
};
