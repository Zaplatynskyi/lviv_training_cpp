//
// Created by cdd on 15.07.19.
//

#include "Graph.h"
#include <iostream>
#include <algorithm>

Graph::Graph(const std::vector<Point> &points):_points(points) {

}

int Graph::calculateVerticals(){
    Point maxItem = *std::max_element(_points.begin(), _points.end());
    int topPoint = maxItem.from;
    return ++topPoint;
}

std::vector<std::vector<int> > Graph::getGraphMatrix(){
    int topPoint = calculateVerticals();
    std::vector<std::vector<int> > graphMatrix(topPoint);
    for (int i=0; i<topPoint; i++)
        graphMatrix[i] = std::vector<int>(topPoint);
    for (const auto &point: _points)
        graphMatrix[point.from][point.to]=point.weight;
    return graphMatrix;
}
