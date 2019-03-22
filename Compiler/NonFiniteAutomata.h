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
    vector<string> differentEdgeValues;

public:
    Node getNFA();

    void setDifferentEdgeValues(string edgeValue);

    vector<string> getDifferentEdgeValues();
};


#endif //COMPILER_NONFINITEAUTOMATA_H
