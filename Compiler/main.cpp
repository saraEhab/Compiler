#include <iostream>
#include "NFAToDFAEngine.h"

int main() {
    NFAToDFA nfaToDFA;
    nfaToDFA.engine();
    Node dfaRoot;
    dfaRoot=(nfaToDFA.dfa.getDFARoot());
    cout<<"we get it :D"<<endl;

    return 0;
}