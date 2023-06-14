#ifndef MAZE_H
#define MAZE_H

#include "graph.h"

class Maze {
public:
    Maze(int width, int height);;

    void createMaze(int creation_width, int creation_height);

    vector<string> findShortestPath(string start, string end);

    int getWidth() const;
    int getHeight() const;

     bool hasTopWall(int x, int y);
     bool hasLeftWall(int x, int y);
     bool hasRightWall(int x, int y);

    std::pair<int, int> playerPosition;
    std::pair<int, int> targetPosition;

    // destructor?
    //~Maze();
    bool movePlayer(int dx, int dy);
    bool hasPlayerReachedTarget();
    void displayMaze(const Graph &graph, const vector<edge> &mst);


    Graph *mazeGraph;
    int width;
    int height;
    std::vector<std::vector<bool>> openSpaces;
private:




};

#endif //MAZE_H
