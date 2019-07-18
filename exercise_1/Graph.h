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

    bool operator <(Point const& Right)
    {
        return from < Right.from;
    }
};

class Graph {
private:
    std::vector<Point> _points;
public:
    Graph(const std::vector<Point> &points);
    const int calculateVerticals();
    std::vector<std::vector<int>> getGraphMatrix();
};


#endif //EXERCISE_1_GRAPH_H
