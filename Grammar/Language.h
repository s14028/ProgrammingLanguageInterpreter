#pragma once

#include <string>

class Language
{
	std::string function;

	std::string assign;

	std::string add;
	std::string subtract;

	std::string divide;
	std::string multiply;

	std::string increment;
	std::string decrement;

	std::string declare;
	std::string print;

	std::string openContext;
	std::string closeContext;

	std::string linEnd;

	friend class Interpreter;

public:
	Language(
		std::string function, std::string assign, 
		std::string add, std::string subtract, 
		std::string divide, std::string multiply, 
		std::string increment, std::string decrement,
		std::string declare, std::string print, std::string openContext, std::string closeContext,
		std::string linEnd)
		:
			function(function), assign(assign), add(add), subtract(subtract),
			divide(divide), multiply(multiply), increment(increment), decrement(decrement), declare(declare),
			print(print), openContext(openContext), closeContext(closeContext), linEnd(linEnd)
	{
	}

	Language(const Language& language)
		:		
			function(language.function), assign(language.assign), add(language.add), subtract(language.subtract),
			divide(language.divide), multiply(language.multiply), increment(language.increment), decrement(language.decrement), declare(language.declare),
			print(language.print), openContext(language.openContext), closeContext(language.closeContext), linEnd(language.linEnd)
	{
	}

static Language defaultGrammar()
{
	Language language
	{
		"function",
		"=",
		"+",
		"-",
		"/",
		"*",
		"++",
		"--",
		"dec",
		"print",
		"{",
		"}",
		";"
	};
	return language;
}



};
/*
 *
 * function foo
 * {
 *  a += b;
 *  return a;
 * }
 * 
 *  a = 10;
 *  b = a;
 *  print a + " " + b endl;
 *
 *  print foo endl;
 * }
 *
 *
 */
