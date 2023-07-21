/* **********************************************************************************************************
Lab ID        : 5.0
Program Title : Dijkstras shortest path Algorithm
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      :   -04-2023
Description   : Program to find shortest path from a single source using dijkstras algorithm

-------------------------------------------------------------------------------------------------------------
Input   : PRE-DEFINED, HARDCODED VALUES...-------------------------------------------------------------------
          n = 8        // number of nodes -i.e- vertices...
          cost[][] = { // adjacency matrix of the given graph, with costs...
              {I , 8 , 2 , 5 , I , I , I , I }, 
              {8 , I , I , 2 , I , 13, I , I }, 
              {2 , I , I , 2 , 5 , I , I , I }, 
              {5 , 2 , 2 , I , 1 , 6 , 3 , I }, 
              {I , I , 5 , 1 , I , I , 1 , I }, 
              {I , 13, I , 6 , I , I , 2 , 3 }, 
              {I , I , I , 3 , 1 , 2 , I , 6 }, 
              {I , I , I , I , I , 3 , 6 , I }
          };
Output  :-----------------------------------------------------------------------------------------------------
          SOURCE  DESTINATION     COST    PATH
          0       0               0       0
          0       1               6       0 -> 2 -> 3 -> 1
          0       2               2       0 -> 2
          0       3               4       0 -> 2 -> 3
          0       4               5       0 -> 2 -> 3 -> 4
          0       5               8       0 -> 2 -> 3 -> 4 -> 6 -> 5
          0       6               6       0 -> 2 -> 3 -> 4 -> 6
          0       7               11      0 -> 2 -> 3 -> 4 -> 6 -> 5 -> 7
 
          MAT   [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]
          
          [0]   **   08   02   05   **   **   **   **
          [1]   08   **   **   02   **   13   **   **
          [2]   02   **   **   02   05   **   **   **
          [3]   05   02   02   **   01   06   03   **
          [4]   **   **   05   01   **   **   01   **
          [5]   **   13   **   06   **   **   02   03
          [6]   **   **   **   03   01   02   **   06
          [7]   **   **   **   **   **   03   06   **

          Status '0' : 1
          Status '1' : 1
          Status '2' : 1
          Status '3' : 1
          Status '4' : 1
          Status '5' : 1
          Status '6' : 1
          Status '7' : 1
-------------------------------------------------------------------------------------------------------------
Algorithm     : Single Source Shortest path (DIJKSTRAS ALGORITHM)....
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <iostream>
#include <cstring>
#include <climits>
#define MAX 10
#define I 999

void displayAll(int cost[][MAX], bool selected[MAX], int n); // Displays all matrices, arrays used (cost, selected)...
void shortestPath(int* distance, bool* selected, int cost[][MAX], int n); // Finds and displays the shortest path using dijkstras algorithm...
int selectMinVertex(int* distance, bool* selected, int cost[][MAX], int n) ;// To find next vertex(u), which is unvisited and has the shortest distance....

int main() { 
    int n = 8; // no. of vertices in the graph...
    int distance[MAX];  // to store the shortest distances of each vertices, wrt the source...
    bool selected[MAX]; // to keep track of vertices visited in the process...

    int cost[MAX][MAX] = { // adjacency matrix of the given graph, with costs...
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
void displayAll(int cost[][MAX], bool selected[MAX], int n) { // this function is a simple array and 2D array (matrix) display...

    std::cout << std::endl << std::endl << "MAT "; // (** => Infinity...)
    for(int i=0; i<n; i++) { 
        std::cout << "  [" << i << "]"; 
    } 
    std::cout << std::endl << std::endl;
    for(int i=0; i<n; i++) 
    { 
        std::cout << "[" << i << "]   ";
        for(int j=0; j<n; j++) 
        {
            if(cost[i][j] == 999) { std::cout << "**   "; }
            else if(cost[i][j] < 10) { std::cout << "0" << cost[i][j] << "   "; }
            else { std::cout << cost[i][j] << "   "; }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i=0; i<n; i++) { // To display the Status -i.e- selected array...
        std::cout << "Status '" << i << "' : " << selected[i] << std::endl; 
    }
}
void shortestPath(int* distance, bool* selected, int cost[][MAX], int n) {

    int u, source = 0;   // setting the '0'th node as the source node...
    std::string path[n]; // creating a string array, to append the paths travelled... 
    for(int i{0}; i<n; i++) {

        distance[i] = I; // set all distances to infinity...
        selected[i] = false;  // set the status to 'not visited' -i.e- not selected any node...
        path[i] = std::to_string(source); // adding source to the path...
    }
    distance[source] = 0; // since no self loop, setting the source distance to '0'...
    for(int i{0}; i<n; i++) {

        u = selectMinVertex(distance, selected, cost, n); // function returns the next vertex to be visited...
        selected[u] = true; // set this vertex as visited...
        
        //! Updating distance of all other vertices, when travelled from selected 'u'.... 
        for(int j{0}; j<n; j++) {
            if(u == j) { continue; } //skipping calculation when path from u -> u is to be calculated. Since no self loops...
            else {
                if(distance[u] + cost[u][j] < distance[j]) {  // main formula ***
                    
                    distance[j] = distance[u] + cost[u][j]; // if another path, that costs less the the previous path is found, update the distances...
                    path[j] = path[u] + " -> " + std::to_string(j); // update the path travelled....
                }
            } // distances for each vertex from the source are checked and updated if a better soln is found...
        } //=> In this funciton, distance from 'u' to all other vertices are checked... 
    }
    std::cout << "SOURCE\tDESTINATION\tCOST\tPATH" << std::endl; // display the required solutions....
    for(int i{0}; i<n; i++) {
        std::cout << source << "\t"
                  << i << "\t\t"
                  << distance[i] << "\t"
                  << path[i]
                  << std::endl;
    }
    displayAll(cost, selected, n); // displays the other matrices and arrays used...
}
int selectMinVertex(int* distance, bool* selected, int cost[][MAX], int n) {
    
    int min_vertex; // required minVertex(to be computed)...
    int temp_cost = I; //
    for(int j{0}; j<n; j++) {
        if((!selected[j]) && (distance[j] < temp_cost)) { 
            /*
                Here, we keep in mind 2 conditions...
                -> 1. select vertex, which is not already visited (!selected[]).
                -> 2. select vertex, with the minimum most distance (min(distance[])). 
            */
            temp_cost = distance[j];
            min_vertex = j;
        }
    }
    return min_vertex; // If such node is found, return...
}
