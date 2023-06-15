#pragma once

// added this forward declaration to avoid circular dependency issues
class GraphNode;

struct edge {
    GraphNode *source;  // 'starting' node of the edge
    GraphNode *destination;  // the 'ending' node of edge
    int weight; 
};
