#include <iostream>
#include "NFAToDFAEngine.h"

int main() {
    NFAToDFA nfaToDFA;
    DFA dfa;
    vector<Node> dfaGraph;


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

    /*make a non finite automaton root*/
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

    /*send the non finite automaton root to deterministic finite automaton*/
    Node nRoot = nfaToDFA.getNFARoot(nfaRoot);

    /*save the different edge values*/

    nfaToDFA.setDifferentEdgeValues(nonFiniteAutomata.getDifferentEdgeValues());

    /*start working by finding the twins for the dfa root*/
    vector<Node> twins = nfaToDFA.findNodeTwins(nRoot, DFARoot);
    if (twins.size()) {
        nfaToDFA.setNodeTwins(twins);
    }

    /*set the deterministic finite automaton root*/
    dfa.setDFARoot(twins[0]);
    /*save the root in the dfa graph*/
    dfaGraph.push_back(twins[0]);

    /*start making the dfa children and complete the deterministic finite automaton */
    for (int i = 1; i < dfaGraph.size(); ++i) {
        nfaToDFA.makeChildren(dfaGraph[i]);
    }

    cout << "we finished" << endl;

    return 0;
}