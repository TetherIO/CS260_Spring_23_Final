#pragma once

class GraphNode;

struct edge {
    GraphNode *source;
    GraphNode *destination;
    int weight;
};
