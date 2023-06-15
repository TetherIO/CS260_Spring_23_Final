#ifndef MAZE_H
#define MAZE_H

#include "graph.h"

class Maze {
public:
    Maze(int width, int height);;

    void createMaze(int creation_width, int creation_height);

    vector<string> findShortestPath(string start, string end); // should I be passing string start/end? 

    // getter methods for width and height
    int getWidth() const;
    int getHeight() const;

    // functions to check if a particular cell in the maze has a top, left, or right wall
     bool hasTopWall(int x, int y);
     bool hasLeftWall(int x, int y);
     bool hasRightWall(int x, int y);

    // player's and target's positions are defined as pairs of ints (x, y)
    std::pair<int, int> playerPosition;
    std::pair<int, int> targetPosition;

    // destructor?
    //~Maze();

    // function to move the player by a certain dx and dy
    bool movePlayer(int dx, int dy);

    bool hasPlayerReachedTarget();

    // function to display the current state of the maze
    void displayMaze(const Graph &graph, const vector<edge> &mst);

    // maze is represented as a graph
    Graph *mazeGraph;
    int width;
    int height;
    // a 2D boolean vector to store which spaces are open
    std::vector<std::vector<bool>> openSpaces;
private:
    // Given the scope of the assignment, I made it all public, but this would need revision if this code was used anywhere -- as unlikely as that is...



};

#endif //MAZE_H
