#include <memory>
#include <vector>
#include <unordered_map>

#include "Expr.h"
#include "Chain.h"
class Context : public Expr
{
	std::shared_ptr<Context> root;
	std::vector<std::shared_ptr<Expr>> exprs;
	std::unordered_map<std::string, std::shared_ptr<Object>>
	pattern::Chain<std::pair<std::shared_ptr<Object>, std::shared_ptr<Expr>>> chain;

	Context();
};
