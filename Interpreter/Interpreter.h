#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <tuple>
#include <vector>

#include "../Function/Function.h"
#include "Functionheader.h"
#include "Language.h"
#include "Object.h"


class Interpreter
{
	Language language;
	const std::vector<std::string>& code;

	unsigned int x;
	unsigned int y;
	unsigned int x1;
	unsigned int y1;

	std::uint64_t charactersLeft;

public:

	Interpreter(Language language, const std::vector<std::string>& code);

	bool findToken(const std::string&, unsigned int&, unsigned int&);
	void passToken(const std::string&, unsigned int&, unsigned int&);

	std::pair<bool, std::string> nextFunctionBlock();
	std::pair<bool, std::string> nextExpression();

	std::optional<std::vector<Expr>> interpretExpression(const FunctionHeader& header, std::string lineOfCode);
	std::vector<Function> interpret();
};
