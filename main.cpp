#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

#include "Grammar/Language.h"
#include "Interpreter/Interpreter.h"

int main(int argc, char** args)
{
	if(argc == 1)
		return 1;

	std::ifstream file(args[1]);
	std::vector<std::string> code;
	std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(),
						std::back_inserter(code));

	file.close();

	Language language = Language::defaultGrammar();

	Interpreter interpreter(language, code);

	interpreter.interpret();

	return 0;
}
