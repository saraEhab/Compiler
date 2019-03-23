//
// Created by Sara on 22/03/2019.
//

#include "NFAToDFA.h"

/*this method makes a reference to the root of non finite automaton
 * to work with in this class*/
Node NFAToDFA::getNFARoot(Node nfaRoot) {
    return nfaRoot;
}

void NFAToDFA::setDFANodeIndex(Node DFANode) {
    DFANode.setIndex(lastTakenIndex);
    lastTakenIndex++;
}

/*this method returns a DFA vector
 * which contains deterministic automaton nodes */
vector<Node> NFAToDFA::getDFA() {
    return DFA;
}

/*this method finds the nodes that can be reached from a dfaNode by epsilon*/
vector<Node> NFAToDFA::findNodeTwins(Node nfaNode, Node dfaNode) {
    vector<Node *> nfaChildren = nfaNode.getChildren();
    vector<string> edgeValues = nfaNode.getEdgeValue();
    vector<Node> twins;
    twins.push_back(nfaNode);
    for (int i = 0; i < edgeValues.size(); ++i) {
        if (edgeValues[i] == "&") {/*& means epsilon*/
            twins.push_back(*nfaChildren[i]);
        }
        if (isAcceptance(*nfaChildren[i])) {
            dfaNode.setStatus(true);
        }
    }
    return twins;
}

/*check if the new state (new nod) that will be added to the dfa graph
 * is already exists or its a new state*/
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

/*this method make a reference to the nfa vector that contains
 * the different input values that have been used for the nfa*/
void NFAToDFA::setDifferentEdgeValues(vector<string> values) {
    for (int i = 0; i < values.size(); ++i) {
        differentEdgeValues.push_back(values[i]);
    }
}

Node NFAToDFA::getDFARoot() {
    return dfa.getDFARoot();
}

/*this method assign the dfa parent node to its dfa children*/
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
                temp = findNodeTwins(childrenForGivenInput[j], child);
                for (int k = 1; k < temp.size(); ++k) {
                    childrenForGivenInput.push_back(temp[k]);
                }
            }
            int index = isNodeExists(childrenForGivenInput);
            if (index == -1) {
                setNodeTwins(childrenForGivenInput);
                setDFANodeIndex(child);
                DFANode.setChild(&child);
                DFA.push_back(child);
            } else {
                DFANode.setChild(&DFA[index]);
            }
        }
    }
}

/*search in the nfa to find the children for a nfa node under a given input*/
vector<Node> NFAToDFA::findChildrenForGivenInput(string inputValue, Node parent) {
    vector<Node> headings;
    vector<string> edgeValues;
    int parentIndex = parent.getIndex();
    vector<Node> twins = nodeTwins[parentIndex];
    for (int i = 0; i < twins.size(); ++i) {
        edgeValues = twins[i].getEdgeValue();
        for (int j = 0; j < edgeValues.size(); ++j) {
            if (edgeValues[j] == inputValue) {
                headings.push_back(*twins[i].getChildren()[j]);
            }
        }
    }
    return headings;
}

/*set the nodeTwins vector
 * which contains the different values for each state in the dfa graph*/
void NFAToDFA::setNodeTwins(vector<Node> twins) {
    nodeTwins.push_back(twins);
}