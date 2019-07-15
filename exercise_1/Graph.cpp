//
// Created by cdd on 15.07.19.
//

#include "Graph.h"
#include <iostream>

Graph::Graph(std::vector<Point> &points) {
    _points = points;
}

int Graph::calculateVerticals(){
    int topPoint = 0;
    for (const auto &point: _points){
        if (point.from>topPoint) {
            topPoint = point.from;
        }
    };
    return ++topPoint;
}

int **Graph::getGraphMatrix(std::vector<Point> &points, int topPoint){
    int **graphMatrix ;
    graphMatrix = new int * [topPoint];
    for (int i=0; i<topPoint; i++) graphMatrix[i] = new int [topPoint];
    for (const auto &point: _points)
        graphMatrix[point.from][point.to]=point.weight;
    return graphMatrix;
}

int *Graph::getPaths(int **GR, int topPoint, int start){
    int *distance, count, index, i, u;
    bool *visited;
    distance = new int [topPoint];
    visited = new bool [topPoint];
    for (i=0; i<topPoint; ++i) { distance[i]=INT32_MAX; visited[i]=false; }
    distance[start]=0;
    for (count=0; count<topPoint-1; ++count) {
        int min=INT32_MAX;
        for (i=0; i<topPoint; ++i)
            if (!visited[i] && distance[i]<=min) { min=distance[i]; index=i; }
        u=index;
        visited[u]=true;
        for (i=0; i<topPoint; ++i)
            if (!visited[i] && GR[u][i] && distance[u]!=INT32_MAX &&
                distance[u]+GR[u][i]<distance[i])
                distance[i]=distance[u]+GR[u][i];
    }
    delete [] visited;
    return distance;
}

void Graph::showPaths(){
    int topPoint = this -> calculateVerticals();
    int **graphMatrix = this -> getGraphMatrix(_points, topPoint);
    int start=0;
    int *distance=this -> getPaths(graphMatrix, topPoint, start);
    int point=start+1;
    for (int i=0; i<topPoint; ++i)
        if (distance[i]!=INT32_MAX)
            std::cout << point << " > " << i+1 << " = " << distance[i] << std::endl;
        else std::cout << point << " > " << i+1 << " = " << "way not found" << std::endl;
}