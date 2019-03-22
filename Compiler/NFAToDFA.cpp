//
// Created by Sara on 22/03/2019.
//

#include "NFAToDFA.h"

void NFAToDFA::getNFARoot() {
    nfaRoot = nonFiniteAutomata.getNFARoot();
}

void NFAToDFA::setDFANodeIndex(Node DFANode) {
    DFANode.setIndex(lastTakenIndex);
    lastTakenIndex++;
}

vector<Node> NFAToDFA::findNodeTwins(Node nfaNode, Node dfaNode, Node parent) {
    vector<Node> nfaChildren = nfaNode.getChildren();
    vector<string> edgeValues = nfaNode.getEdgeValue();
    vector<Node> twins;
    twins.push_back(nfaNode);
    for (int i = 0; i < edgeValues.size(); ++i) {
        if (edgeValues[i] == "&") {
            twins.push_back(nfaChildren[i]);
        }
        if (isAcceptance(nfaChildren[i])) {
            dfaNode.setStatus(true);
        }
    }
    return twins;
}

int NFAToDFA::isNodeExists(vector<Node> twins) {}

bool NFAToDFA::isAcceptance(Node node) {}

void NFAToDFA::setDifferentEdgeValues() {}

Node NFAToDFA::getDFARoot() {}

void NFAToDFA::makeChildren(Node DFANode) {}

vector<Node> NFAToDFA::findChildrenForGivenInput(string inputValue, Node parent) {}

void NFAToDFA::setNodeTwins(vector<Node> twins) {}