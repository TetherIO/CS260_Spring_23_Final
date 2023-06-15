#include "graph.h"
#include "graph_node.h"

#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

struct QueueNode {
    string currentName;
    vector<string> path;
};

// constructor initilizes a certain size maze (should have probably just gone with fixed size for this project)
Graph::Graph(int width, int height) : width(width), height(height) {}

// destructor to clear graph up
Graph::~Graph() {
    for (auto node: nodes) {
        delete node;
    }
    nodes.clear();
}


// creates the edge if the two nodes exist
void Graph::addEdge(string sourceName, string destinationName, int weight) {
    GraphNode *sourceNode = nodeMap[sourceName];
    GraphNode *destinationNode = nodeMap[destinationName];

    if (sourceNode == nullptr) {
        throw std::runtime_error("Source node not found");
    }
    if (destinationNode == nullptr) {
        throw std::runtime_error("Destination node not found");
    }

    sourceNode->addEdge(destinationNode, weight);
    allEdges.push_back(edge{sourceNode, destinationNode, weight}); // Use 'edge' not 'Edge'
}


int Graph::getSize() {
    return nodes.size();
}

// MST, Kruskal's algorithm implementation
string Graph::minimumSpanningTree() {
    vector<edge *> allEdges;
    vector<edge *> MST;

    // Gather all edges
    for (auto node: nodes) {
        vector<edge *> neighbors = node->getNeighbors();
        for (auto neighbor: neighbors) {
            allEdges.push_back(neighbor);
        }
    }

    // Sort edges by weight
    std::sort(allEdges.begin(), allEdges.end(), [](edge *a, edge *b) {
        return a->weight < b->weight;
    });

    // Create a map to store the parent of each node (for the union-find structure)
    std::map<string, string> parent;
    for (auto node: nodes) {
        parent[node->getValue()] = node->getValue();
    }

    for (auto edge: allEdges) {
        // If adding this edge does not create a cycle, add it to the MST
        string root1 = findRoot(parent, edge->source->getValue());
        string root2 = findRoot(parent, edge->destination->getValue());
        if (root1 != root2) {
            MST.push_back(edge);
            parent[root1] = root2;  // union of the two sets
        }
    }

    // constructs the output string of the MST (in this version I orginally passed by string instead of vector of edges)
    string output = "";
    for (auto edge: MST) {
        output += edge->source->getValue() + " -> " + edge->destination->getValue() + "\n";
    }

    return output;
}

// helper function to find the root of a node (for the union-find structure)
string Graph::findRoot(std::map<string, string> &parent, string node) {
    if (parent[node] == node) {
        return node;
    }
    return findRoot(parent, parent[node]);
}


// BFS to be replaced by more technical algorithm to find distance to every tile from every tile of the 'maze' graph
vector<string> Graph::findShortestPath(string sourceName, string destinationName) {
    // The BFS algorithm uses a queue, so we'll create one to hold nodes to visit
    std::queue<QueueNode> toVisit;

    // We also need a way to keep track of which nodes we've already visited, so we'll use a set for that
    std::set<string> visited;

    // We start the BFS at the source node, so we'll create a QueueNode for it and add it to the queue
    QueueNode sourceNode = {sourceName, {sourceName}};
    toVisit.push(sourceNode);

    while (!toVisit.empty()) {
        // get the next node to visit from the front of the queue
        QueueNode currentNode = toVisit.front();
        toVisit.pop();

        // If this node is the destination, we've found a path!
        if (currentNode.currentName == destinationName) {
            return currentNode.path;
        }

        // Mark the current node as visited
        visited.insert(currentNode.currentName);

        // Add all unvisited neighbors of the current node to the queue
        for (auto edge: getNode(currentNode.currentName)->getNeighbors()) {
            string neighborName = edge->destination->getValue();
            if (visited.count(neighborName) == 0) {
                // The neighbor hasn't been visited yet, so we'll create a QueueNode for it
                QueueNode neighborNode = {neighborName, currentNode.path};
                neighborNode.path.push_back(neighborName);
                toVisit.push(neighborNode);
            }
        }
    }

    //return empty path if no path is found
    return {};
}


GraphNode *Graph::getNode(string name) {
    // iterate over all nodes in the graph
    return nodeMap[name];
}

// alternate MST implementation using kruskal vs prim
vector<edge> Graph::kruskalMST() {
    sort(allEdges.begin(), allEdges.end(), [](const edge &a, const edge &b) {
        return a.weight < b.weight;
    });

    map<GraphNode*, GraphNode*> parents;
    for (GraphNode* node : nodes) {
        parents[node] = node;
    }

    vector<edge> mst;

    for (edge &edge : allEdges) {
        GraphNode* sourceParent = parents[edge.source];
        while (sourceParent != parents[sourceParent]) {
            sourceParent = parents[sourceParent];
        }

        GraphNode* destParent = parents[edge.destination];
        while (destParent != parents[destParent]) {
            destParent = parents[destParent];
        }

        if (sourceParent != destParent) {
            mst.push_back(edge);
            parents[destParent] = sourceParent;
        }
    }

    return mst;
}

int Graph::getWidth() const {
    return width;
}

int Graph::getHeight() const {
    return height;
}

// add a node to the graph
void Graph::addNode(const string& nodeName) {
    // Check if the node already exists
    if (nodeMap.find(nodeName) != nodeMap.end()) {
        throw std::runtime_error("Node already exists");
    }

    // create a new node and add it to the graph's node list and map
    GraphNode* newNode = new GraphNode(nodeName);
    newNode->graph = this;  // Set the graph pointer

    // Add node to node map and node list
    nodeMap[nodeName] = newNode;
    nodes.push_back(newNode);
}

