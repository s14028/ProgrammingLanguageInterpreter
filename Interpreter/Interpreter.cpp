#include "Interpreter.h"

#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>

#include "object.h"
#include "function.h"
#include "functionheader.h"

bool Interpreter::findToken(const std::string& token, unsigned int& x, unsigned int& y)
{
	unsigned char left = 0;
	while(token.size() - left <= charactersLeft)
	{
		if(x == code[y].size())
		{
			x = 0;
			y++;
		}
		if(core[y][x] == token[left])
		{
			left++;
			if(left == token.size())
				return true;
		}

		charactersLeft--;
		x++;
	}

	return false;
}

/**
	*	Warning.
	*	If sentence only has a prefix of token passed, it will stil set x position to first another character. If you will pass "asd" token and the line will be asb x pointer will be settle on 2.
	*/
void Interpreter::passToken(const std::string& token, unsigned int& x, unsigned int& y)
{
	unsigned char left = 0;
	while(y < code.size())
	{
		while(x + (token.size() - left) <= code.size[y].size())
		{
			if(code[y][x] != token[left])
				return;
			left++;

			if(left == token.size())
				left = 0;

			charactersLeft--;
			x++;
		}

		y++;
	}
}

std::pair<bool, std::string> Interpreter::nextContextBlock()
{
	bool foundL = findToken(language.openContext, x, y);
	bool foundR = findToken(language.closeContext, x1, y1);

	if(foundL && !foundR)
		return {false, "Context opened at " + x + " column, " + y + " row. But never closed."};
	if(!foundL && foundR)
		return {false, "Context closed at " + x1 + " column, " + y1 + " row. But never opened."};
	
	return {true, ""};
}

std::pair<bool, std::string> Interpreter::nextExpression()
{
	passToken(" ", x, y);
	
	x1 = x;
	y1 = y;

	bool found = findToken(language.linEnd, x1, y1);
	if(!found)
	{
		if(y < code.size())
			return {false, "Couldn't find " + language.linEnd + " token."};
		return {false, "0"};
	}
	return {true, ""};
}

std::vector<Function> Interpreter::interpret()
{
	std::vector<Function> functionList;
	while(current < code.size())
	{
		auto be = nextFunctionBlock(current);
		current = be.last + 1;

		std::optional<Function> option = buildFunctionBlock(be);

		if(!option)
		return {};

		functionList.push_back(*option);
	}
	return functionList;
}

std::optional<std::vector<Expr>> Interpreter::interpretExpression(const FunctionHeader& header, std::string lineOfCode)
{
	std::regex.searchLast(lineOfCode, patterns);
}
