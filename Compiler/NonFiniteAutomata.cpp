//
// Created by Sara on 22/03/2019.
//

#include "NonFiniteAutomata.h"

Node NonFiniteAutomata::getNFARoot() {
    return root;
}

void NonFiniteAutomata::setDifferentEdgeValues(string edgeValue) {
    differentEdgeValues.push_back(edgeValue);
}

vector<string> NonFiniteAutomata::getDifferentEdgeValues() {
    return differentEdgeValues;
}