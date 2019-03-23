//
// Created by Sara on 22/03/2019.
//

#ifndef COMPILER_NFATODFAENGINE_H
#define COMPILER_NFATODFAENGINE_H

#include <iostream>
#include "NFAToDFA.h"

using namespace std;

class NFAToDFAEngine {
private:
    NFAToDFA nfaToDFA;
    DFA dfa;
    vector<Node> dfaGraph;
    NonFiniteAutomata nonFiniteAutomata;

public:
    int engine(Node);

};


#endif //COMPILER_NFATODFAENGINE_H
