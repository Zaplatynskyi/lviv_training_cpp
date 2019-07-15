#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"

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
    graph.showPaths();

    return 0;
}