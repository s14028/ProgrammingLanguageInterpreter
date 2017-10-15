#pragma once
#include <memory>
#include "Object.h"

class Expr
{
public:

    virtual ~Expr()
    {
    }
    virtual std::shared_ptr<Object> operator()(std::shared_ptr<Object>);
};
