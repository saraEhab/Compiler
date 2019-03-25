//
// Created by Sara on 22/03/2019.
//

#ifndef COMPILER_NFATODFA_H
#define COMPILER_NFATODFA_H

#include "Node.h"
#include "NonFiniteAutomata.h"
#include "DFA.h"

using namespace std;


class NFAToDFA {
private:
    NonFiniteAutomata nonFiniteAutomata;
    DFA dfa;
    vector<vector<Node>> nodeTwins;
    int lastTakenIndex = 0;
    vector<string> differentEdgeValues;
    vector<Node *> DFA;

public:

    vector<Node> findNodeTwins(Node nfaNode, Node dfaNode);

    int isNodeExists(vector<Node> twins);

    bool isAcceptance(Node node);

    void setDifferentEdgeValues(vector<string> values);

    void makeChildren(Node DFANode);

    vector<Node> findChildrenForGivenInput(string inputValue, Node parent);

    void setNodeTwins(vector<Node> twins);

    vector<Node *> getDFA();

    void setDFA(Node *);
};


#endif //COMPILER_NFATODFA_H
