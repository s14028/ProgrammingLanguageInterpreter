#pragma once
#include "object.h"
#include "ioperation.h"
#include <memory>
#include "type.h"
class Decimal : Object, IOperation
{
public:
    int i;
    Decimal(int i) : i(i){}
    ~Decimal()
    {

    }


    std::shared_ptr<IOperation> operator+(std::shared_ptr<IOperation> o)
    {
        o = dynamic_cast<std::shared_ptr<Decimal>>(o);
        return std::make_shared<Decimal>(i + o->i);
    }

    std::shared_ptr<IOperation> operator-(std::shared_ptr<IOperation> p)
    {
        p = dynamic_cast<std::shared_ptr<Decimal>>(p);
        return std::make_shared<Decimal>(i + p->i);
    }

    std::shared_ptr<IOperation> operator*(std::shared_ptr<IOperation> e)
    {
        e = dynamic_cast<std::shared_ptr<Decimal>>(e);
        return std::make_shared<Decimal>(i + e->i);
    }

    std::shared_ptr<IOperation> operator/(std::shared_ptr<IOperation> r)
    {
        r = dynamic_cast<std::shared_ptr<Decimal>>(r);
        return std::make_shared<Decimal>(i + r->i);
    }

    std::shared_ptr<Object> copy() override
    {
        return std::make_shared<Decimal>(i);
    }

    Type type() override
    {
        return Type::Decimal;
    }
};