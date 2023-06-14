#include "maze.h"

#include <iostream>
#include <random>

Maze::Maze(int width, int height) {
    this->width = width;
    this->height = height;
    openSpaces = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
    mazeGraph = new Graph(width, height);
    createMaze(width,height);
    playerPosition = std::make_pair(0, 0);
    targetPosition = std::make_pair(width - 1, height - 1);

}

// ran out of time for multi graph implementation for create a non-perfect maze
void Maze::createMaze(int creation_width, int creation_height) {
    // initialize all nodes and mark odd-numbered indices as open spaces for test

    for (int i = 0; i < creation_width; i++) {
        for (int j = 0; j < creation_height; j++) {
            openSpaces[j][i] = (i % 2 == 1 && j % 2 == 1);
            if (openSpaces[j][i]) {
                mazeGraph->addNode(std::to_string(i) + "," + std::to_string(j));
            }
        }
    }
}



void Maze::displayMaze(const Graph& graph, const vector<edge>& mst) {
    int width = graph.getWidth(); // You need to provide this method
    int height = graph.getHeight(); // You need to provide this method

    for (int y = 0; y < height; ++y) {
        // Print top walls
        for (int x = 0; x < width; ++x) {
            std::cout << "#";
            if (hasTopWall(x, y)) {
                std::cout << "##";
            } else {
                std::cout << " #";
            }
        }
        std::cout << "#" << std::endl;

        // Print left walls and passages
        for (int x = 0; x < width; ++x) {
            if (hasLeftWall(x, y)) {
                std::cout << "##";
            } else {
                std::cout << " #";
            }
            std::cout << " ";
        }

        // Print right wall of the last cell in the row
        if (hasRightWall(width - 1, y)) {
            std::cout << "##" << std::endl;
        } else {
            std::cout << " #" << std::endl;
        }
    }

    // Print bottom walls of the last row
    for (int x = 0; x < width; ++x) {
        std::cout << "###";
    }
    std::cout << "#" << std::endl;
}

vector<string> Maze::findShortestPath(string start, string end) {
    //to find and print the shortest path through the maze.
    vector<string> path = mazeGraph->findShortestPath(start, end);
    for (auto node: path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return path;
}


bool Maze::movePlayer(int dx, int dy) {
    int new_x = playerPosition.first + dx;
    int new_y = playerPosition.second + dy;

    // Check if the new position is within the boundaries of the maze
    if (new_x < 0 || new_x >= width || new_y < 0 || new_y >= height) {
        return false;
    }

    std::string newPosition = std::to_string(new_x) + "," + std::to_string(new_y);

    // Check if the new position is a valid node and is an open space
    if (mazeGraph->getNode(newPosition) != nullptr && openSpaces[new_y][new_x]) {
        playerPosition.first = new_x;
        playerPosition.second = new_y;
        return true;
    } else {
        return false;
    }
}


bool Maze::hasPlayerReachedTarget() {
    return playerPosition == targetPosition;
}

int Maze::getWidth() const {
    return width;
}

int Maze::getHeight() const {
    return height;
}


bool Maze::hasTopWall(int x, int y) {
    // Check if there is a wall at the top of the cell at position (x, y)
    if (y > 0) {
        std::string currentNode = std::to_string(x) + "," + std::to_string(y);
        std::string topNode = std::to_string(x) + "," + std::to_string(y - 1);
        for (const auto& edge : mazeGraph->allEdges) {
            if ((edge.source->getValue() == currentNode && edge.destination->getValue() == topNode) ||
                (edge.source->getValue() == topNode && edge.destination->getValue() == currentNode)) {
                return false;  // No wall
            }
        }
    }
    return true;  // Wall exists
}

bool Maze::hasLeftWall(int x, int y) {
    // Check if there is a wall on the left of the cell at position (x, y)
    if (x > 0) {
        std::string currentNode = std::to_string(x) + "," + std::to_string(y);
        std::string leftNode = std::to_string(x - 1) + "," + std::to_string(y);
        for (const auto& edge : mazeGraph->allEdges) {
            if ((edge.source->getValue() == currentNode && edge.destination->getValue() == leftNode) ||
                (edge.source->getValue() == leftNode && edge.destination->getValue() == currentNode)) {
                return false;  // No wall
            }
        }
    }
    return true;  // Wall exists
}

bool Maze::hasRightWall(int x, int y) {
    // Check if there is a wall on the right of the cell at position (x, y)
    if (x < width - 1) {
        std::string currentNode = std::to_string(x) + "," + std::to_string(y);
        std::string rightNode = std::to_string(x + 1) + "," + std::to_string(y);
        for (const auto& edge : mazeGraph->allEdges) {
            if ((edge.source->getValue() == currentNode && edge.destination->getValue() == rightNode) ||
                (edge.source->getValue() == rightNode && edge.destination->getValue() == currentNode)) {
                return false;  // No wall
            }
        }
    }
    return true;  // Wall exists
}
