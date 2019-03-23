#include <iostream>
#include "NFAToDFAEngine.h"

int main() {
    NFAToDFA nfaToDFA;
    DFA dfa;
    vector<Node> dfaGraph;

    Node nfaRoot ;
    nfaRoot.setStatus(true);
    nfaRoot.setIndex(0);

    Node DFARoot;
    DFARoot.setIndex(0);

    NonFiniteAutomata nonFiniteAutomata;
    nonFiniteAutomata.setNFARoot(nfaRoot);

//    NFAToDFAEngine nfaToDFAEngine;
//    cout << nfaToDFAEngine.engine(nonFiniteAutomata.getNFARoot()) << endl;

    Node nRoot=nfaToDFA.getNFARoot(nfaRoot);
    nfaToDFA.setDifferentEdgeValues();
    vector<Node> twins = nfaToDFA.findNodeTwins(nRoot, DFARoot);
    if (twins.size()) {
        nfaToDFA.setNodeTwins(twins);
    }
    for (int i = 1; i <dfaGraph.size() ; ++i) {
        nfaToDFA.makeChildren(dfaGraph[i]);
    }

    dfaGraph=nfaToDFA.getDFA();
    dfa.setDFARoot(dfaGraph[0]);

    return 0;
}