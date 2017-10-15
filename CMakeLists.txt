project(PLanguageInterpreter)
cmake_minimum_required(VERSION 2.8.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

include(Type/CMakeLists.txt)
include(Interpreter/CMakeLists.txt)
include(Function/CMakeLists.txt)
include(Grammar/CMakeLists.txt)
include(Operation/CMakeLists.txt)


add_executable(main main.cpp
	${type_headers}
	${type_sources}
	${interpreter_headers}
	${interpreter_sources}
	${function_headers}
	${function_sources}
	${grammar_headers}
	${grammar_sources}
	${operation_headers}
	${operation_sources}
	)
