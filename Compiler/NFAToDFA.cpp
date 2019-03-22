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

Node NFAToDFA::getDFARoot() {
    return dfa.getDFARoot();
}

void NFAToDFA::makeChildren(Node DFANode) {
    string currentValue;
    vector<Node> childrenForGivenInput;
    vector<Node> temp;
    for (int i = 0; i < differentEdgeValues.size(); ++i) {
        Node child;
        currentValue = differentEdgeValues[i];
        childrenForGivenInput = findChildrenForGivenInput(currentValue, DFANode);
        if (childrenForGivenInput.size() != 0) {
            DFANode.setEdgeValue(currentValue);
            for (int j = 0; j < childrenForGivenInput.size(); ++j) {
                temp = findNodeTwins(childrenForGivenInput[j], child, DFANode);
                for (int k = 1; k < temp.size(); ++k) {
                    childrenForGivenInput.push_back(temp[k]);
                }
            }
            int index = isNodeExists(childrenForGivenInput);
            if (index == -1) {
                setNodeTwins(childrenForGivenInput);
                setDFANodeIndex(child);
                DFANode.setChild(child);
                DFA.push_back(child);
            } else {
                DFANode.setChild(DFA[index]);
            }
        }
    }
}

vector<Node> NFAToDFA::findChildrenForGivenInput(string inputValue, Node parent) {
    vector<Node> headings;
    vector<string> edgeValues;
    int parentIndex = parent.getIndex();
    vector<Node> twins = nodeTwins[parentIndex];
    for (int i = 0; i < twins.size(); ++i) {
        edgeValues = twins[i].getEdgeValue();
        for (int j = 0; j < edgeValues.size(); ++j) {
            if (edgeValues[j] == inputValue) {
                headings.push_back(twins[i].getChildren()[j]);
            }
        }
    }
    return headings;
}

void NFAToDFA::setNodeTwins(vector<Node> twins) {}