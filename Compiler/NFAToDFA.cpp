//
// Created by Sara on 22/03/2019.
//

#include <iostream>
#include "NFAToDFA.h"

/*this method returns a DFA vector
 * which contains deterministic automaton nodes */
vector<Node *> NFAToDFA::getDFA() {
    return dfaGraph;
}

void NFAToDFA::setDFA(Node *node) {
    dfaGraph.push_back(node);
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
                    i=nodeTwins.size();
                    break;
                }
            }
        }
    }
    return index;
}

bool NFAToDFA::isAcceptance(Node node) {
    if (node.getStatus() == true)
        return true;
    return false;
}

/*this method make a reference to the nfa vector that contains
 * the different input values that have been used for the nfa*/
void NFAToDFA::setDifferentEdgeValues(vector<string> values) {
    for (int i = 0; i < values.size(); ++i) {
        differentEdgeValues.push_back(values[i]);
    }
}


/*this method assign the dfa parent node to its dfa children*/
void NFAToDFA::makeChildren(Node* DFANode) {
    string currentValue;
    vector<Node> childrenForGivenInput;
    vector<Node> temp;
    for (int i = 0; i < differentEdgeValues.size(); ++i) {
        Node *child = new Node();
        currentValue = differentEdgeValues[i];
        childrenForGivenInput = findChildrenForGivenInput(currentValue, *DFANode);
        if (childrenForGivenInput.size() != 0) {
            DFANode->setEdgeValue(currentValue);
            for (int j = 0; j < childrenForGivenInput.size(); ++j) {
                temp = findNodeTwins(childrenForGivenInput[j], *child);
                for (int k = 1; k < temp.size(); ++k) {
                    childrenForGivenInput.push_back(temp[k]);
                }
            }
            int index = isNodeExists(childrenForGivenInput);
            if (index == -1) {
                setNodeTwins(childrenForGivenInput);
                lastTakenIndex++;
                child->setIndex(lastTakenIndex);
                DFANode->setChild(child);
                dfaGraph.push_back(child);
            } else {
                DFANode->setChild(dfaGraph[index]);
            }
        }
    }
    if (DFANode->getIndex() == 0) {
        DFARoot = *DFANode;
        dfa.setDFARoot(&DFARoot);
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

void NFAToDFA::engine() {
    /*make a non finite automaton nodes*/

    Node nfaRoot;
    Node node_1;
    Node node_2;
    Node node_3;
    Node node_4;
    Node node_5;

    Node *nfaRoot_ptr = &nfaRoot;
    Node *node_1_ptr = &node_1;
    Node *node_2_ptr = &node_2;
    Node *node_3_ptr = &node_3;
    Node *node_4_ptr = &node_4;
    Node *node_5_ptr = &node_5;

    nfaRoot.setStatus(false);
    nfaRoot.setIndex(0);
    nfaRoot.setChild(node_1_ptr);
    nfaRoot.setChild(node_4_ptr);
    nfaRoot.setEdgeValue("&");
    nfaRoot.setEdgeValue("&");


    node_1.setStatus(false);
    node_1.setIndex(1);
    node_1.setEdgeValue("a");
    node_1_ptr->setChild(node_2_ptr);

    node_2.setStatus(false);
    node_2.setIndex(2);
    node_2.setEdgeValue("&");
    node_2_ptr->setChild(node_3_ptr);

    node_4.setStatus(false);
    node_4.setIndex(4);
    node_4.setEdgeValue("b");
    node_4_ptr->setChild(node_5_ptr);

    node_5.setStatus(false);
    node_5.setIndex(5);
    node_5.setEdgeValue("&");
    node_5_ptr->setChild(node_3_ptr);

    node_3.setStatus(false);
    node_3.setIndex(3);
    node_3.setEdgeValue("&");
    node_3_ptr->setChild(nfaRoot_ptr);


    /*make a root for deterministic finite automaton*/
    Node DFARoot;
    DFARoot.setIndex(0);

    /*set the non finite automaton root*/
    NonFiniteAutomata nonFiniteAutomata;
    nonFiniteAutomata.setNFARoot(nfaRoot);

    nonFiniteAutomata.setDifferentEdgeValues("a");
    nonFiniteAutomata.setDifferentEdgeValues("b");

    /*save the different edge values*/
    setDifferentEdgeValues(nonFiniteAutomata.getDifferentEdgeValues());

    /*start working by finding the twins for the dfa root*/
    vector<Node> twins = findNodeTwins(nonFiniteAutomata.getNFARoot(), DFARoot);
    if (twins.size()) {
        setNodeTwins(twins);
    }
    dfaGraph.push_back(&DFARoot);
    makeChildren(&DFARoot);
    /*start making the dfa children and complete the deterministic finite automaton */
    for (int i = 1; i < dfaGraph.size(); ++i) {
        Node *temp = dfaGraph[i];
        makeChildren(temp);

    }

}