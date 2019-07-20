//
// Created by cdd on 18.07.19.
//

#include "ShortestPath.h"
#include <iostream>
#include <algorithm>

ShortestPath::ShortestPath(const std::vector<std::vector<int>>&matrix,const int& topPoint):_matrix(matrix),_topPoint(topPoint) {

}

std::vector<int> ShortestPath::getPaths(std::vector<std::vector<int> > graphMatrix, int topPoint, int start){
    int  count, index, u;
    std::vector<bool> visited(topPoint);
    std::vector<int> distance(topPoint);
    for (int i=0; i<topPoint; ++i) {
        distance[i]=std::numeric_limits<int>::max();
        visited[i]=false;
    }
    distance[start]=0;
    for (count=0; count<topPoint-1; ++count) {
        int min=std::numeric_limits<int>::max();
        for (int i=0; i<topPoint; ++i)
            if (!visited[i] && distance[i]<=min){
                min=distance[i];
                index=i;
            }
        u=index;
        visited[u]=true;
        for (int i=0; i<topPoint; ++i)
            if (!visited[i] && graphMatrix[u][i] && distance[u]!=std::numeric_limits<int>::max() &&
                distance[u]+graphMatrix[u][i]<distance[i])
                distance[i]=distance[u]+graphMatrix[u][i];
    }
    return distance;
}


std::ostream & operator << (std::ostream &out,ShortestPath & object)
{
    int start=0;
    std::vector<int> distance= object.getPaths(object._matrix, object._topPoint, start);
    int point=start+1;
    for (int i=0; i<object._topPoint; ++i)
        if (distance[i]!=std::numeric_limits<int>::max())
            std::cout << point << " > " << i+1 << " = " << distance[i] << std::endl;
        else std::cout << point << " > " << i+1 << " = " << "way not found" << std::endl;
}