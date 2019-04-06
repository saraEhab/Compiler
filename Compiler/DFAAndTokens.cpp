//
// Created by Sara on 22/03/2019.
//

#include "DFAAndTokens.h"
#include "MinDFA.h"

void DFAAndTokens::takeMinDfa(Node *node) {
    minDfaRoot = node;
}

Node *DFAAndTokens::getNextNode(char input) {
    string temp = "";
    temp += input;
    vector<Node *> children = pointer->getChildren();
    vector<string> edgeValues = pointer->getEdgeValue();
    for (int i = 0; i < edgeValues.size(); ++i) {
        if (edgeValues[i] == temp) {
            pointer = children[i];
            return children[i];
        }
    }
}

void DFAAndTokens::resetDFA() {
    pointer = minDfaRoot;
}