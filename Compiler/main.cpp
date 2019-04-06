#include <iostream>
#include "NFAToDFAEngine.h"
#include "MinDFA.h"
#include "DFAAndTokens.h"

int main() {

    NFAToDFA *nfaToDFA = NFAToDFA::getInstance();
    nfaToDFA->engine();
    Node dfaRoot;
    dfaRoot = (nfaToDFA->dfa.getDFARoot());

    /*fix the first node (DFARoot) in the dfaGraph
     * it always has a wrong value*/
    Node *temp = &dfaRoot;
    nfaToDFA->dfaGraph[0] = temp;

    Node *minDfaRoot;

    MinDFA *minDFA = MinDFA::getInstance();
    minDFA->engine();
    minDfaRoot = minDFA->minDFARoot;

    DFAAndTokens dfaAndTokens;
    dfaAndTokens.takeMinDfa(minDfaRoot);

    cout << "done :D" << endl;
    return 0;
}