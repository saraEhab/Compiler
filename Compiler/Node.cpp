//
// Created by Sara on 22/03/2019.
//
#include "Node.h"

bool status;
int index;
vector<Node> children;
vector<string> edgeValue;

void Node::setStatus(bool statusValue) {
    status = statusValue;
}

bool Node::getStatus() {
    return status;
}

void Node::setIndex(bool indexValue) {
    index = indexValue;
}

int Node::getIndex() {
    return index;
}

void Node::setChild(Node child) {
    children.push_back(child);
}

vector<Node> Node::getChildren() {
    return children;
}

void Node::setEdgeValue(string edge) {
    edgeValue.push_back(edge);
}

vector<string> Node::getEdgeValue() {
    return edgeValue;
}