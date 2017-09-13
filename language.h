#pragma once
#include <cstdint>
#include <vector>

#include <string>
#include <tuple>
#include "function.h"
#include "object.h"

class Language
{
    std::vector<std::string>& code;

public:
    Language(const std::vector<std::string>& code);


    std::vector<std::shared_ptr<Object>> copy(const std::vector<std::shared_ptr<Object>>& arguments);

    Function buildFunctionBlock(std::pair<std::uint64_t, std::uint64_t> be, const std::vector<std::shared_ptr<Object>>& arguments);

    std::pair<std::uint64_t, std::uint64_t> nextFunctionBlock(std::uint64_t begin);

    std::vector<Function> interpret();
};

/*
 *
 * foo(a, b)
 * {
 *  a += b
 *  return a
 * }
 *
 * main()
 * {
 *  a = 10
 *  b = a
 *  print a
 *
 *  print foo(a, b)
 * }
 *
 *
 */