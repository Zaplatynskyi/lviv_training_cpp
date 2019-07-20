//
// Created by cdd on 18.07.19.
//

#ifndef EXERCISE_1_SHORTESTPATH_H
#define EXERCISE_1_SHORTESTPATH_H
#include <vector>
#include <iostream>

class ShortestPath {
private:
    std::vector<std::vector<int>> _matrix;
    int _topPoint;
public:
    ShortestPath(const std::vector<std::vector<int>>&matrix,const int& topPoint);
    std::vector<int> getPaths(std::vector<std::vector<int> > graphMatrix, int V, int start);
    friend std::ostream & operator << (std::ostream &out,ShortestPath & object);
};

#endif //EXERCISE_1_SHORTESTPATH_H
