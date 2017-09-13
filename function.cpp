#include <memory>
#include "function.h"
#include "object.h"
#include "expr.h"
Function::Function()
{

}

std::shared_ptr<Object> Function::execute()
{
    if(expressions.size() == 0)
        return std::shared_ptr<Object>(nullptr);
    for(unsigned int i = 0; i < expressions.size() - 1; i++)
        (*this->expressions[i])(params, locals);
    return (*this->expressions[expressions.size() - 1])(params, locals);
}