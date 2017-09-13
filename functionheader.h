#pragma once
#include <cstdint>
#include <vector>

#include <string>
#include <tuple>

#include "function.h"
#include "object.h"

class FunctionHeader
{
    void readSymbols(std::vector<std::string> code, std::pair<std::uint64_t, std::uint64_t> bd);

public:

    std::uint16_t argumentCount;
    std::uint16_t localCount;

    FunctionHeader(std::vector<std::string> code, std::pair<std::uint64_t, std::uint64_t> bd);

    std::pair<std::vector<std::shared_ptr<Object>>, std::vector<std::shared_ptr<Object>>> init();
};