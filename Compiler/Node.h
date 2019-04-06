//
// Created by Sara on 22/03/2019.
//

#ifndef COMPILER_NODE_H
#define COMPILER_NODE_H

#include <vector>
#include <string>

using namespace std;

class Node {

private:
    bool status;/*0 means internal node 1 means acceptance node*/
    int index;/*index of the node*/
    vector<Node *> children;
    vector<string> edgeValue;

public:

    void setStatus(bool statusValue);

    bool getStatus();

    void setIndex(int indexValue);

    int getIndex();

    void setChild(Node *child);

    vector<Node *> getChildren();

    void alterChild(int index , Node* newChild);

    void setEdgeValue(string edge);

    vector<string> getEdgeValue();

};


#endif //COMPILER_NODE_H