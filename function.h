#pragma once
#include <memory>
#include <vector>
#include "object.h"
#include "expr.h"

class Function
{
    std::vector<std::shared_ptr<Object>> params;
    std::vector<std::shared_ptr<Object>> locals;
    std::vector<std::shared_ptr<Expr>> expressions;
public:
    Function();
    std::shared_ptr<Object> execute();
};