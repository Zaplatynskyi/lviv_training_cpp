#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
#include "ShortestPath.h"

int main(int argc, char **argv) {
    std::vector<Point> points;
    Point point;
    std::ifstream file(argv[1]);

    if (file.is_open()) {
        while (file>>point.from>>point.to>>point.weight) {
            points.push_back(point);
        }
    }
    else
        perror("file not open");

    Graph graph(points);
    std::vector<std::vector<int>> matrix;
    matrix = graph.getGraphMatrix();
    int topPoint = graph.calculateVerticals();
    ShortestPath path(matrix,topPoint);
    std::cout<<path;
    return 0;
}