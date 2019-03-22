cmake_minimum_required(VERSION 3.13)
project(Compiler)

set(CMAKE_CXX_STANDARD 11)

add_executable(Compiler main.cpp Node.cpp Node.h NonFiniteAutomata.cpp NonFiniteAutomata.h NFAToDFA.cpp NFAToDFA.h MinDFA.cpp MinDFA.h DFAAndTokens.cpp DFAAndTokens.h DFA.cpp DFA.h)