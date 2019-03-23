//
// Created by Sara on 22/03/2019.
//

#include "NFAToDFAEngine.h"

int NFAToDFAEngine::engine(Node root) {
    Node nRoot=nfaToDFA.getNFARoot(root);
    //nfaToDFA.setDifferentEdgeValues();
    vector<Node> twins = nfaToDFA.findNodeTwins(nRoot, nfaToDFA.getDFARoot());
    if (twins.size()) {
        nfaToDFA.setNodeTwins(twins);
    }
    // dfaGraph=nfaToDFA.getDFA();
    dfa.setDFARoot(dfaGraph[0]);
    for (int i = 1; i <dfaGraph.size() ; ++i) {
        nfaToDFA.makeChildren(dfaGraph[i]);
    }

    return 0;
}