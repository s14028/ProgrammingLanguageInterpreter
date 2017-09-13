#pragma once
#include <memory>
#include <vector>
#include <cstdint>

class Expr
{

    std::uint16_t lvalue;
    std::uint16_t rvalue;
public:
    Expr()
    {

    }

    virtual ~Expr()
    {

    }

    virtual std::shared_ptr<Object> operator()(std::vector<std::shared_ptr<Object>>, std::vector<std::shared_ptr<Object>>);
protected:

    static bool isLocal(std::uint16_t value)
    {
        value >>= 15;
        return value == 1u;
    }

    static void asLocal(std::uint16_t& value)
    {
        value |= 32768;
    }

    std::pair<std::vector<std::shared_ptr<Object>>*, std::vector<std::shared_ptr<Object>>*> buffors(
                std::vector<std::shared_ptr<Object>>* param,
                std::vector<std::shared_ptr<Object>>* local
            )
    {
        return std::make_pair((isLocal(lvalue) ? local : param), (isLocal(rvalue) ? local : param));
    }

    void setPositions()
    {
        rvalue <<= 1;
        rvalue >>= 1;
        lvalue <<= 1;
        lvalue >>= 1;
    }
};