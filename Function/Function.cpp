#include <memory>
#include "Function.h"
#include "Object.h"
#include "Expr.h"
Function::Function()
{

}

std::shared_ptr<Object> Function::operator()()
{
	body->operator();
}
