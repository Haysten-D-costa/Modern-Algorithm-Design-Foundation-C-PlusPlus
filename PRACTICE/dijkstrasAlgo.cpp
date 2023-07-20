#include <iostream>
#include <cstring>
#define MAX 10
#define I 999

void shortestPath(int* distance, bool* selected, int cost[][MAX], int n) {

    int u, v = 0;
    std::string path[n];
    for(int i{0}; i<n; i++) {

        distance[i] = I;
        selected[i] = false;
        path[i] = std::to_string(v);
    }
    distance[v] = 0;
    for(int i{0}; i<n; i++) {

        //! To find next vertex(u)....
        int temp_cost = I;
        for(int j{0}; j<n; j++) {
            if((!selected[j]) && (distance[j] < temp_cost)) {
                temp_cost = distance[j];
                u = j;
            }
        }
        selected[u] = true;

        //! Updating distance, when travelled from selected 'u'.... 
        for(int j{0}; j<n; j++) {
            if(u == j) { continue; }
            else {
                if(distance[u] + cost[u][j] < distance[j]) {
                    
                    distance[j] = distance[u] + cost[u][j];
                    path[j] = path[u] + " -> " + std::to_string(j);
                }
            }
        }
    }
    std::cout << "SOURCE\tDESTINATION\tCOST\tPATH" << std::endl;
    for(int i{0}; i<n; i++) {
        std::cout << v << "\t"
                  << i << "\t\t"
                  << distance[i] << "\t"
                  << path[i]
                  << std::endl;
    }
}
int main() {
    int n = 8;
    int distance[MAX];
    bool selected[MAX];

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
    shortestPath(distance, selected, cost, n);
    return 0;
}