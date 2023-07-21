#include <iostream>
#define MAX 10
#define I 999
 
void shortestPath(int cost[][MAX], int distance[], bool selected[], int n) {

    int u, v = 0;
    std::string path[n];
    for(size_t i{0}; i<n; i++) {

        distance[i] = I;
        selected[i] = false;
        path[i] = std::to_string(v);
    }
    distance[v] = 0;

    for(int i{0}; i<n; i++) {
        
        int temp_cost = I;
        for(size_t j{0}; j<n; j++) {
            if((!selected[j]) && (distance[j] < temp_cost)) {
                temp_cost = distance[j];
                u = j;
            }
        }
        selected[u] = true;

        for(size_t j{0}; j<n; j++) {
            if(u == j) { continue; }
            else {
                if(distance[u] + cost[u][j] < distance[j]) 
                {    
                    distance[j] = distance[u] + cost[u][j];
                    path[j] = path[u] + " -> " + std::to_string(j);
                }
            }
        }
    }
    std::cout << "Src" << "\t" << "Destn" << "\t" << "MinCost" << "\t" << "Path" << "\t" << std::endl;
    for(int i=0; i<n; i++) {
        std::cout << v << "\t";
        std::cout << i << "\t";
        if(distance[i] == I)     std::cout << '-' << "\t" << '-' << std::endl;
        else std::cout << distance[i] << "\t" << path[i] << std::endl;
    }
}

int main() {

    int n = 8;          // Number of vertices...
    int distance[MAX];  // Distance...
    bool selected[MAX]; // Status -i.e- visited / unvisited...

    int cost[MAX][MAX] = {
        {I , 8 , 2 , 5 , I , I , I , I }, 
        {8 , I , I , 2 , I , 13, I , I }, 
        {2 , I , I , 2 , 5 , I , I , I }, 
        {5 , 2 , 2 , I , 1 , 6 , 3 , I }, 
        {I , I , 5 , 1 , I , I , 1 , I }, 
        {I , 13, I , 6 , I , I , 2 , 3 }, 
        {I , I , I , 3 , 1 , 2 , I , 6 }, 
        {I , I , I , I , I , 3 , 6 , I }
    };
    shortestPath(cost, distance, selected, n);
    return(0);
}