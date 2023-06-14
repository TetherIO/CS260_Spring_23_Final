#pragma once

#include <vector>
#include <string>
#include <map>
#include <utility>

#include "edge.h"          // Add this line
#include "graph_node.h"    // Add this line

using std::vector;
using std::pair;
using std::map;
using std::string;

class Graph {
    int width;
    int height;

public:
    // constructor and destructor
    Graph(int width, int height);
    ~Graph();

    int getWidth() const;
    int getHeight() const;


    // add node

    // add edge
    void addEdge(string sourceName, string destinationName, int weight);

    // get size of graph nodes list
    int getSize();

    // minimum spanning tree
    string minimumSpanningTree();

    // find shortest path between two nodes
    vector<string> findShortestPath(string sourceName, string destinationName);

    GraphNode* getNode(string name);
    vector<edge> kruskalMST();

    vector<edge> allEdges;

    void addNode(const string &nodeName);

// some way of storing my data...
vector<GraphNode*> nodes;
private:
    map<string, GraphNode*> nodeMap;

    // helper method to find a node given its name
    string findRoot(std::map<string, string>& parent, string node);


};
};
