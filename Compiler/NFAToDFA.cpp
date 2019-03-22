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

int NFAToDFA::isNodeExists(vector<Node> twins) {
    vector<Node> twin_i;
    int index = -1;
    for (int i = 0; i < nodeTwins.size(); ++i) {
        twin_i = nodeTwins[i];
        if (twin_i.size() == twins.size()) {
            for (int j = 0; j < twin_i.size(); ++j) {
                if (twin_i[j].getIndex() != twins[j].getIndex()) {
                    index = -1;
                    break;
                } else {
                    index = i;
                }
            }
        }
        return index;
    }


}

bool NFAToDFA::isAcceptance(Node node) {
    return node.getStatus();
}

void NFAToDFA::setDifferentEdgeValues() {
    differentEdgeValues = nonFiniteAutomata.getDifferentEdgeValues();
}

Node NFAToDFA::getDFARoot() {}

void NFAToDFA::makeChildren(Node DFANode) {}

vector<Node> NFAToDFA::findChildrenForGivenInput(string inputValue, Node parent) {}

void NFAToDFA::setNodeTwins(vector<Node> twins) {}