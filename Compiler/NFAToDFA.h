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
    Node nfaRoot;
    NonFiniteAutomata nonFiniteAutomata;
    DFA dfa;
    vector<vector<Node>> nodeTwins;
    int lastTakenIndex = 0;
    vector<string> differentEdgeValues;
    vector<Node> DFA;

public:
    Node getNFARoot(Node nfaRoot);

    void setDFANodeIndex(Node DFANode);

    vector<Node> findNodeTwins(Node nfaNode, Node dfaNode);

    int isNodeExists(vector<Node> twins);

    bool isAcceptance(Node node);

    void setDifferentEdgeValues();

    Node getDFARoot();

    void makeChildren(Node DFANode);

    vector<Node> findChildrenForGivenInput(string inputValue, Node parent);

    void setNodeTwins(vector<Node> twins);

    vector<Node> getDFA();
};


#endif //COMPILER_NFATODFA_H
