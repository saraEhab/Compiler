//
// Created by Sara on 22/03/2019.
//

#include "NFAToDFA.h"

void NFAToDFA::getNFARoot() {
    nfaRoot = nonFiniteAutomata.getNFARoot();
}

void NFAToDFA::setDFANodeIndex(Node DFANode) {

}

vector<Node> NFAToDFA::findNodeTwins(Node nfaNode, Node dfaNode, Node parent) {}

int NFAToDFA::isNodeExists(vector<Node> twins) {}

bool NFAToDFA::isAcceptance(Node node) {}

void NFAToDFA::setDifferentEdgeValues() {}

Node NFAToDFA::getDFARoot() {}

void NFAToDFA::makeChildren(Node DFANode) {}

vector<Node> NFAToDFA::findChildrenForGivenInput(string inputValue, Node parent) {}

void NFAToDFA::setNodeTwins(vector<Node> twins) {}