#include "language.h"
#include <vector>
#include <string>

#include <cstdint>
#include "object.h"
#include "function.h"


Language::Language(const std::vector<std::string>& code) : code(code)
{

}


std::vector<Object> Language::copy(const std::vector<std::shared_ptr<Object>>& arguments)
{
    std::vector<std::shared_ptr<Object>> result(arguments.size());

    for(size_t i = 0; i < arguments.size(); i++)
        result[i] = arguments[i].copy();

    return result;
}

Function buildFunctionBlock(std::pair<std::uint64_t, std::uint64_t> be, const std::vector<std::shared_ptr<Object>>& arguments)
{
    Function function;
}

std::pair<std::uint64_t, std::uint64_t> nextFunctionBlock(std::uint64_t begin);

std::vector<Function> interpret();