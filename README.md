# CS260_Spring_23_Final

## NOTE

BFS algorithm to be replaced by Djikstra's. 

## Introduction
The code will compile and run, but the Maze functionality is currently lacking. Fitting the minimum requirements, my addNode function in the Graph class adds a vertex to the graph; likewise my addEdge function adds an edge between two nodes; the shortest path again used a very simple BFS algorithm (and likely will add a second after the deadline); and there are two MST implementations that are slightly different in output using kruskal's algorithm. The MST used by the maze is given by minimumSpanningTree(), but I was able to create the kruskalMST with just a couple discrete math books and minimal reference code from Tony Gaddis and StackExachange.

## Analyzing Complexity

Complexity Analysis at time of submission was as follows: 

1. GraphNode::addEdge O(1)
   - Constant time because we are just appending an end to end of array (vector)
2. GraphNode::getValue O(1)
   - Again constant time as we're just accessing a member variable
3.  GraphNode::getNeighbors O(1)
   - Another access which is constant
4. Graph::addEdge O(1)
   - Again constant as we're just adding an edge to a vector
5. Graph::getSize O(1)
   - Returning a size value, which is constant-time
6. Graph::minimumSpanningTree O(N log N)
   - For this one, I'm guessing that sorting would dominate the complexity -- as it seems like the union-find operation is intuitively less intense, but I'd have to ask one of the research faculty I know for a real understanding.
7. Graph::findShortestPath O(1)
   - I think this would be constant? as the the BFS algorithm is just reliant on number of vertices and edges?
8. 

![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-2.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-3.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-4.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-5.jpg?raw=true)
