//we will add the pragma once in a few minutes, so we can see the issue that it prevents!
#pragma once

#include <string>
#include <vector>

struct edge;

using std::string;
using std::vector;

class Graph;

class GraphNode {
    public:
    // constructor
    GraphNode(string newName);
    ~GraphNode();
    // add edge
    void addEdge(GraphNode *destination, int weight);
    // get value of this node
    string getValue();
    // get neighbors as a list of pointers ( might be better with my small graph to use copies of edge instead of pointers)
    vector<edge *> getNeighbors();
    Graph *graph;
    private:
    //stored value
    string value;

    // reference to neighbors
    vector<edge *> neighbors;

};
