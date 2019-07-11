#include <iostream>
#include <fstream>

const int V=8;

int *Dijkstra(int **GR, int V, int st) {
    int *distance, count, index, i, u;
    bool *visited;
    distance = new int [V];
    visited = new bool [V];
    for (i=0; i<V; i++) { distance[i]=INT32_MAX; visited[i]=false; }
    distance[st]=0;
    for (count=0; count<V-1; count++) {
        int min=INT32_MAX;
        for (i=0; i<V; i++)
            if (!visited[i] && distance[i]<=min) { min=distance[i]; index=i; }
        u=index;
        visited[u]=true;
        for (i=0; i<V; i++)
            if (!visited[i] && GR[u][i] && distance[u]!=INT32_MAX &&
                distance[u]+GR[u][i]<distance[i])
                distance[i]=distance[u]+GR[u][i];
    }
    return distance;
}

int main(int argc, char **argv) {
    int start, **GR;
    GR = new int * [V];
    for (int i=0; i<V; i++) GR[i] = new int [V];
    std::ifstream file(argv[1]);
    int  from, to, weight;
    if (file.is_open()) {
                while (file>>from>>to>>weight) {
                       GR[from][to]=weight;
                    }
                }
    else
        perror("file not open");
    start=0;
    int *distance=Dijkstra(GR, V, start);
    int m=start+1;
    for (int i=0; i<V; i++)
        if (distance[i]!=INT32_MAX)
            std::cout << m << " > " << i+1 << " = " << distance[i] << std::endl;
        else std::cout << m << " > " << i+1 << " = " << "way not found" << std::endl;
    return 0;
}