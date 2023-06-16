# CS260_Spring_23_Final

## NOTE

### Fell Short
As we chuckled about in class, sometimes even a simple maze project ends up being unexpectedly challenging. This was a brutal one for me; it required quite a bit of head scratching and turning to past math textbooks to try and remember the algorithms. It came down to a few years of experience, about 15 years ago, with programming in x86 assembly that hellped with pointers and understanding how programs are stored in memory. Regardless, I will need to contine to work on my C/C++ because it was clear how reliant I was on VSCode and CLION to essentially complete and format my code. I'm submitting this with what I believe show understanding of the topics and of the project's requirements -- but again, the original plan (see images below) was. I'll continue to work on this after my other finals tomorrow as I think I'm close to implementing a maze that displays on the commandline. 

### IMMEDIATE ATTENTION
* ~~Finish complexity analysis~~
* Expand comments explaining my process (then screenshot into 
* Replace BFS with Dijkstra's for ShortestPath


### IF TIME PERMITS
* Use Prim's for createMaze to replace basic 'odd' method used as a placeholder
* Delete edges in destructor of Graph(?)
* Convert to undirected or detect all neighbors instead of 'one way' neighbor
* Fix the maze print function
* Fix the detection methods for building maze
* iterate over neighbors to delete each object in graphnode destructor(?)



### BACKBURNER
* Create edges in either (exclusive) Graph or Node
* Implement my other kruskal's in the maze class (fix cycle issue)
* addEdge exception handling for sourceNode/destinationNode not found in nodeMap (getNode too)
* addNode exception thrown, change to return an error/flag
* Edges as structs in Graph and pointers in GraphNode class (streamline this)
* steamline as graph has both vector 'nodes' and map 'nodemap' (harder to keep consistent)
* public vs private 'graph' in graphnode class
* Replace everything with smart pointers as hinted at in class (?)
* check if destination is null pointer in addEdge before dereferencing (?)
* delete graph class members "width" and "height" (are they being used somewhere that I'm not noticing?)
* addEdge checking for existing edge(?)



## Introduction
The code will compile and run, but the Maze functionality is currently lacking. Fitting the minimum requirements, my addNode function in the Graph class adds a vertex to the graph; likewise my addEdge function adds an edge between two nodes; the shortest path again used a very simple BFS algorithm (and likely will add a second after the deadline); and there are two MST implementations that are slightly different in output using kruskal's algorithm. The MST used by the maze is given by minimumSpanningTree(), but I was able to create the kruskalMST with just a couple discrete math books and minimal reference code from Tony Gaddis and StackExachange.

## Analyzing Complexity

A bit cursory as my Firefox tab crashed the first time after an hour of typing -- like an idiot I was editing the README directly in my browser without a backup.

##### GraphNode

* GraphNode::addEdge O(1)
   - Constant time because we are just appending an end to end of array (vector)
* GraphNode::getValue O(1)
   - Again constant time as we're just accessing a member variable
* GraphNode::getNeighbors O(1)
   - Another access which is a constant time operation

#####  Graph
* Graph::addEdge O(1)
   - Again constant as we're just adding an edge to a vector
* Graph::getSize O(1)
   - Returning a size value, which is constant-time
* Graph::minimumSpanningTree O(n log n)
   - I'm guessing the sort is most time intensive. The sort requires considering n edges, and then the union operations consider each edge but the number of consideration decreases as as the tree grows.
* Graph::findShortestPath O(n)
   - This one is tricky, as I imagine it's dependent on both vertices and edges, but not the product of the two.
* Graph::kruskalMST O(n log n)   
   - Again, O(n log n) like the other kruskal implementation.
* Graph::addNode O(1)
   - assuming an insertion is constant time
* Graph::getNode O(1)
   - same reasoning as addNode
* Graph::getEdges O(n)
   - where n is the number of edgesb because adding all edges to set
   - 
##### Maze
* Maze() O(1)
   - initiliazing n number of cells in a vector? maybe not considered
* Maze::createMaze O(n)
   - number of cells in maze looped
* Maze::displayMaze O(n)
   - by same thinking as createMaze, n number of cells
* Maze::findShortestPath O(1n)
   - again dependent on vertices and edges, would be O(n^2) if we found shortest path for every node to every other node
* Maze::movePlayer O(1)
   - bhecks and manipulates a couple variables
* Maze::hasPlayerReacherdTarget O(1)
   - a simple check if two pairs are equal
* Maze::getWidth/Height O(1)
   - these will likely be deleted by they are simple getters and thus constant
* Maze::has(Top/Left/Right)Wall O(n)
   - where n is number of edges, these three method iterate over all edges
 

## Required functions

### A function to add a new vertex to the graph
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/addVertexRequirment.png)

### A function to add a new edge between two vertices of the graph
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/addEdgeRequirment.png)

### A function for a shortest path algorithm
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/addFindShortestPathRequirment.png)

### A function for a minimum spanning tree algorithm



## More analysis: Kruskal's

### minimumSpanningTree
* Gather up the edges in a vector (Kruskal considers all the edges vs Prim's which considers the edges that emanate from the current vertex.
* Sort all of those edges by their weight in ascending order.
* Create a map for the parent of each node ultilizing a disjoint-set structure (Union-Find). This allows us to track which vertices are in which connected components to prevent the cycles when edges are added (smallest edge considered so cycles are very possible).
* Iterating over sorted edges and checking for Cycles as hinted to above. I use findRoot() to check if vertices are in "set", if not the edge is added and merges the constitutent vertices of the component.

### kruskalMST
* Sorts all edges in a similiar manner (as is the hallmark of Kruskal's)
* Same use of disjoint-set (union-find); each node is own parent initially, etc.
* Iterating over sorted edges and checking for cycles as above. The difference is in the union operation; in kruskalMST the parent of the root of the destionation is set to the root of the source. The minimumSpanningTree has the parent of the root of the source set to the root of the destionation. That said, in both, roots are checked to prevent cycles and  operations performed by updating the parent of the destination vertex's root to the source vertex's root.

As can be seen in the code, there's not much difference between the two. The first was more reliant on inspiration from outside sources and the second was more independent from the experience of creating the first and from the discrete math series I thook for my undergrad degree. As far as returned structures, the vector of edges made sense in the context of updating a gameboard to be displayed. The formatted string from minimalSpanningTree seemed good for debugging or a text based game, for example. 




![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-2.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-3.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-4.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-5.jpg?raw=true)
