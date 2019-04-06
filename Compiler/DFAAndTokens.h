//
// Created by Sara on 22/03/2019.
//

#ifndef COMPILER_DFAANDTOKENS_H
#define COMPILER_DFAANDTOKENS_H

#include "Node.h"

using namespace std;

class DFAAndTokens {

private:
    Node * pointer ;
    Node *minDfaRoot;

public:
    Node* getNextNode(char input);

    void resetDFA();

    void takeMinDfa(Node*);

};


#endif //COMPILER_DFAANDTOKENS_H
