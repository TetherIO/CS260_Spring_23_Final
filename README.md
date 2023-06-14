# CS260_Spring_23_Final

## NOTE

### Fell Short ###
As we chuckled about in class, sometimes even a simple maze project ends up being unexpectedly challenging. This was a brutal one that required quite a bit of head scratching. It really came down to my experience with x86 assembly as a kid that saved me with pointers and understanding how programs are stored in memory. Regardless, I will need to contine to work on my C/C++ because it was clear how reliant I was on VSCode and CLION. I'm submitting this with what I believe are the minimum requirements. I'll continue to work on this over the next few days regardless as I think I'm close to implementing a maze that actually works. The last submitted commits before the deadline were commented with "uploaded from Pinebook". 

###TO DO:###
* 
* Finish complexity analysis
* Better comments explaining my process


BFS algorithm to be replaced by Djikstra's. 

## Introduction
The code will compile and run, but the Maze functionality is currently lacking. Fitting the minimum requirements, my addNode function in the Graph class adds a vertex to the graph; likewise my addEdge function adds an edge between two nodes; the shortest path again used a very simple BFS algorithm (and likely will add a second after the deadline); and there are two MST implementations that are slightly different in output using kruskal's algorithm. The MST used by the maze is given by minimumSpanningTree(), but I was able to create the kruskalMST with just a couple discrete math books and minimal reference code from Tony Gaddis and StackExachange.

## Analyzing Complexity

Complexity Analysis at time of submission was as follows: 

* GraphNode::addEdge O(1)
   - Constant time because we are just appending an end to end of array (vector)
* GraphNode::getValue O(1)
   - Again constant time as we're just accessing a member variable
* GraphNode::getNeighbors O(1)
   - Another access which is a constant time operation
* Graph::addEdge O(1)
   - Again constant as we're just adding an edge to a vector
* Graph::getSize O(1)
   - Returning a size value, which is constant-time
* Graph::minimumSpanningTree O(n log n)
   - For this one, I'm guessing that sorting would dominate the complexity -- as it seems like the union-find operation is intuitively less intense, but I'd have to ask one of the research faculty I know for a real understanding. As we discussed in class, the sort requires that we sort
* Graph::findShortestPath O(1)
* Graph::kruskalMST O(N log N)   - Again, O(N log N) as the sort requires 

![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-2.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-3.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-4.jpg?raw=true)
![](https://github.com/TetherIO/CS260_Spring_23_Final/blob/main/Data%20Structures-5.jpg?raw=true)
