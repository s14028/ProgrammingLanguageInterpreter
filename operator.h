#pragma once
#include "object.h"
#include "expr.h"
#include <memory>
#include <vector>



class Operator : Expr
{
    uchar op;
public:
    Operator(uchar op)
    {
        this->op = op;
    }

    std::shared_ptr<Object> operator()(std::vector<std::shared_ptr<Object>> params, std::vector<std::shared_ptr<Object>> locals)
    {
        std::shared_ptr<Object> pointer;
        auto pair = buffors(&params, &locals);
        setPositions();

        auto f = dynamic_cast<IOperation*>(std::get<0>(pair)[lvalue].get());
        auto s = dynamic_cast<IOperation*>(std::get<1>(pair)[rvalue].get());

        switch(op)
        {
        case '*':
            pointer = (*f) * (*s);
            break;
        case '/':
            pointer = (*f) / (*s);
            break;
        case '+':
            pointer = (*f) + (*s);
            break;
        case '-':
            pointer = (*f) - (*s);
            break;
        }

        return pointer;
    }
};