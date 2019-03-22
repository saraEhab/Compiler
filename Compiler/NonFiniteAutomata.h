//
// Created by Sara on 22/03/2019.
//

#ifndef COMPILER_NONFINITEAUTOMATA_H
#define COMPILER_NONFINITEAUTOMATA_H

#include "Node.h"

using namespace std;

class NonFiniteAutomata {
private:
    Node root;
    vector<string> differentEdgeValues;/*contains the different values an edge can take*/

public:
    Node getNFARoot();

    void setNFARoot(Node nfaRoot);

    void setDifferentEdgeValues(string edgeValue);

    vector<string> getDifferentEdgeValues();
};


#endif //COMPILER_NONFINITEAUTOMATA_H
