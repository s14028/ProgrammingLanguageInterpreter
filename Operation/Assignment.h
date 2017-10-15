#pragme once
#include <memory>
#include <tuple>
#include "expr.h"
#include "object.h"

class Assignment : Expr
{
    std::shared_ptr<Object> operator()
    (std::vector<std::shared_ptr<Object>> params, std::vector<std::shared_ptr<Object>> locals) override
    {
        auto pair = buffors(&params, &locals);
        setPositions();

        std::get<0>(pair)[lvalue] = std::get<1>(pair)[rvalue];

        return std::get<0>(pair)[lvalue];
    }
};