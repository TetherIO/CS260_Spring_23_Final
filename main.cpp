#include "edge.h"
#include "graph_node.h"
#include "graph.h"
#include <iostream>

int main() {
    using namespace std;


    cout << "hello world?" << endl;
    // create edge to test simple edge situations
    edge *newEdge = new edge{nullptr, nullptr, 42};
    cout << "newEdge->source: " << newEdge->source << "\nnewEdge->destination: " << newEdge->destination << "\nnewEdge->weight: " << newEdge->weight << endl;

    // create a simple node to test
    GraphNode *newNode = new GraphNode("Albany"); // default constructor (the constructor without parameters), does not need parentheses...
    cout << "newNode->getValue(): " << newNode->getValue() << "\nnewNode->getNeighbors().size(): " << newNode->getNeighbors().size() << endl;
    // add edge to node
    newNode->addEdge(newNode, 1);
    cout << "newNode->getNeighbors().size(): " << newNode->getNeighbors().size() << endl;
    cout << "newNode->getNeighbors()->at(0)->destination->getValue(): " << newNode->getNeighbors().at(0)->destination->getValue() << endl;

    // delete node
    delete newNode;

    // Test addNode
    cout << "=== Testing addNode ===\n";
    Graph graph(10, 10);
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");
    graph.addNode("F");
    cout <<"Graph size is: " << graph.getSize() << " (Expected: 6)\n";
    cout << "Adding a duplicate node 'A'...\n";
    try {
        graph.addNode("A");
    } catch (const std::runtime_error& e) {
        cout << "Caught exception: " << e.what() << "\n";
    }
    cout << "Graph size after duplicate addition: " << graph.getSize() << " (Expected: 6)\n";
    cout << "\n";

    // Test addEdge
    cout << "=== Testing addEdge ===\n";
    cout << "Adding edges A->B, B-> C, C->A, D->E with weights 1, 2, 3, 4.\n";
    graph.addEdge("A", "B", 1);
    graph.addEdge("B", "C", 2);
    graph.addEdge("C", "A", 3);
    graph.addEdge("D", "E", 4);
    cout << "Graph edges count for node A: " << graph.getNode("A")->getNeighbors().size() << " (Expected: 1)\n";
    cout << "Graph edges count for node B: " << graph.getNode("B")->getNeighbors().size() << " (Expected: 1)\n";
    cout << "Graph edges count for node C: " << graph.getNode("C")->getNeighbors().size() << " (Expected: 1)\n";
    cout << "Graph edges count for node D: " << graph.getNode("D")->getNeighbors().size() << " (Expected: 1)\n";
    cout << "Adding an edge with a non-existent source node...\n";
    try {
        graph.addEdge("X", "B", 5);
    } catch (const std::runtime_error& e) {
        cout << "Caught exception: " << e.what() << "\n";
    }
    cout << "Adding an edge with a nonexistent destnation node...\n";
    try {
        graph.addEdge("B", "Y", 5);
    } catch (const std::runtime_error& e) {
        cout << "Caught exception: " << e.what() << "\n";
    }
    cout << "\n";

    // Test findShortestPath
    cout << "=== Testing findShortestPath ===\n";
    cout << "Finding shortest path from A to C.\n";
    vector<string> path = graph.findShortestPath("A", "C");
    cout << "shortest path from A to C is:";
    for (const auto &p : path) {
        cout << p << " ";
    }
    cout << "(Expected: A B C)\n";
    cout << "Finding shortest path from B to D.\n";
    path = graph.findShortestPath("B", "D");
    cout << "Shortest path from B to D is: ";
    for (const auto &p : path) {
        cout << p << " ";
    }
    cout << "(Expected: B C A D)\n";
    cout << "Finding shortest path from a to E (no path exists)...\n";
    vector<string> invalidPath = graph.findShortestPath("A", "E");
    if (invalidPath.empty()) {
        cout << "No path exists from A to E.\n";
    }
    cout << "\n";

    // Test minimumSpanningTree
    cout << "=== Testing minimumSpanningTree ===\n";
    cout << "Finding minimum spanning tree.\n";
    string mst = graph.minimumSpanningTree();
    cout << "Minimum spanning tree is: \n" << mst << "(Expected: A -> B, B -> C, D -> E)\n";
    cout << "\n";

    // Test kruskalMST
    cout << "=== Testing kruskalMST ===\n";
    cout << "Finding minimum spanning tree using Kruskal's algorithm.\n";
    vector<edge> mstEdges = graph.kruskalMST();
    cout << "Minimum spanning tree edges are: \n";
    for (const auto &e : mstEdges) {
        cout << e.source->getValue() << " -> " << e.destination->getValue() << "\n";
    }
    cout << "\n";

    return 0;
}




/*#include "maze.h"
#include <iostream>
#include <limits>

constexpr int MAZE_WIDTH = 21; // Ensure it's an odd number
constexpr int MAZE_HEIGHT = 21; // Ensure it's an odd number


int main() {
    int width = 10;
    int height = 10;

    Graph graph(width, height);
    // read the size of the maze
    Maze maze(MAZE_WIDTH, MAZE_HEIGHT);
    while (true) {
        // display the maze
        maze.displayMaze();
        //read the player's move
        char move;

        std::cin >> move;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int dx = 0, dy = 0;
        switch (move) {
            case 'w':
                dy = -1;
                break;
            case 'a':
                dx = -1;
                break;
            case 's':
                dy = 1;
                break;
            case 'd':
                dx = 1;
                break;
            default:
                std::cout << "Invalid move! Use 'w' for up, 'a' for left, 's' for down, 'd' for right.\n";
                continue;
        }
        // try to make the move
        if (!maze.movePlayer(dx, dy)) {
            std::cout << "Invalid move!" << std::endl;
            continue;
        }
        // check if the player has reached the target
        if (maze.hasPlayerReachedTarget()) {
            std::cout << "You reached the target!" << std::endl;
            break;
        }
    }

    return 0;
} */
