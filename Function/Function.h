#pragma once
#include <memory>
#include <vector>
#include "Object.h"
#include "Expr.h"
#include "Context.h"

class Function : public Expr
{
	std::shared_ptr<Context> body;
public:
  Function();

	std::shared_ptr<Object> operator()() override;

	operator bool()
	{
		return body;
	}

};
