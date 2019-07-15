//
// Created by cdd on 15.07.19.
//

#ifndef EXERCISE_1_GRAPH_H
#define EXERCISE_1_GRAPH_H

#include <vector>

struct Point {
    int from = 0;
    int to = 0;
    int weight = 0;

};

class Graph {
private:
    std::vector<Point> _points;
public:
    Graph(std::vector<Point> &points);
    int calculateVerticals();
    int **getGraphMatrix(std::vector<Point> &points, int topPoint);
    void showPaths();
    int *getPaths(int **GR, int V, int start);
};


#endif //EXERCISE_1_GRAPH_H
