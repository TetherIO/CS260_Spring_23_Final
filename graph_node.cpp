#include "graph_node.h"
#include "edge.h"

GraphNode::GraphNode(string newName) {
    value = newName;
    // vector<GraphNode *> neighbors is a direct object, not a pointer to one, so when this GraphNode gets constructed, that direct object gets constructed
}

GraphNode::~GraphNode() {
    //delete class code based on some double deletions possibilities with my graph class
    neighbors.clear();
}

void GraphNode::addEdge(GraphNode *destination, int weight) {
    edge *newEdge = new edge{this, destination, weight};
    neighbors.push_back(newEdge);
}

string GraphNode::getValue() {
    return value;
}

vector<edge *> GraphNode::getNeighbors() {
    return neighbors;
}
