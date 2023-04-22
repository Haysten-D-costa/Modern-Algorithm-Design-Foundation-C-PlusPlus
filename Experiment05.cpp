/* **********************************************************************************************************
Lab ID        : 5.0
Program Title : Dijkstras shortest path Algorithm
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      :   -04-2023
-------------------------------------------------------------------------------------------------------------
Description   : Program to find shortest path from a single source using dijkstras algorithm
Input         : -
Output        : -
Algorithm     : -
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <iostream>
#define I 9999 // Infinity value...

using namespace std;

void shortestPath(int Cost[][10], int Distance[], bool S[], int n);   // Function to find shortest path from initial node(0) to others...
void shortestPath01(int Cost[][10], int Distance[], bool S[], int n); // Function to find shortest path from initial node(0) to others...
void displayContent(int Cost[][10], int Distance[], bool S[], int n); // Function to display the Cost, Distanceance and Status (matrx and arrays)....

int main()
{
    bool S[10];
    int n = 8, Distance[10];
    
    int Cost[10][10] = {  /* matrix : Example '02' Given by math sir...*/
        {I , 8 , 2 , 5 , I , I , I , I }, 
        {8 , I , I , 2 , I , 13, I , I }, 
        {2 , I , I , 2 , 5 , I , I , I }, 
        {5 , 2 , 2 , I , 1 , 6 , 3 , I }, 
        {I , I , 5 , 1 , I , I , 1 , I }, 
        {I , 13, I , 6 , I , I , 2 , 3 }, 
        {I , I , I , 3 , 1 , 2 , I , 6 }, 
        {I , I , I , I , I , 3 , 6 , I }
    };
    // int Cost[10][10] = { /* Matrix : Example '01' Given by teacher... VERIFIED*/
    //     {I , 50, 45, 10, I , I },
    //     {I , I , 10, 15, I , I },
    //     {I , I , I , I , 30, I },
    //     {20, I , I , I , 15, I },
    //     {I , 20, 35, I , I , I },
    //     {I , I , I , I , 3 , I }
    // };
    shortestPath(Cost, Distance, S, n); // Calls function to find the shortest paths...
    cout << endl << endl;

    return(0);
}
void displayContent(int Cost[][10], int Distance[], bool S[], int n)
{
    cout << endl << endl << "MAT ";
    for(int i=0; i<n; i++) { cout << "  [" << i << "]"; } cout << endl << endl;
    for(int i=0; i<n; i++) { // To display the Cost matrix...
        cout << "[" << i << "]   ";
        for(int j=0; j<n; j++) {
            if(Cost[i][j] == 9999) { cout << "**   "; }
            else if(Cost[i][j] < 10) { cout << "0" << Cost[i][j] << "   "; }
            else { cout << Cost[i][j] << "   "; }
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0; i<n; i++) { // To display the Distanceance array...
        cout << "Shortest Distance from 0 -> " << i << " : " << Distance[i] << endl; 
    }
    cout << endl;
    for(int i=0; i<n; i++) { // To display the Status array...
        cout << "Status '" << i << "' : " << S[i] << endl; 
    }
    cout << endl << endl;
}
void shortestPath(int Cost[][10], int Distance[], bool S[], int n) // Done by me...
{
    int v=0, u; 
    for(int i=0; i<n; i++) {
        Distance[i] = I;
        S[i] = false;
    }
    Distance[v] = 0; // Setting distance of source node to '0'...
    
    for(int i=0; i<n; i++) 
    {
        int temp_cost = I;
        for(int j=0; j<n; j++) { // This will select vertex which is 'unvisited' and has 'minimum distance'...
            if((!S[j]) && (Distance[j]) < temp_cost) {
                temp_cost = Distance[j];
                u = j;
            }
        }
        S[u] = true;
        for(int j=0; j<n; j++) { // This will update distance of each vertex from the selected source vertex(u), except it will not update its own distance, from itself(-i.e- it'll continue)...
            if(j == u) { continue; }
            else if((Distance[u] + Cost[u][j]) < Distance[j]) { Distance[j] = Distance[u] + Cost[u][j]; }
        }
        for(int i=0; i<n; i++) { // Displays the distances updated at each pass... 
                if(i == 0) {
                    cout << endl << "Distances updated from " << u << " :" << endl;
                }
                cout << i << " : " << Distance[i] << endl;
            }
    }
    displayContent(Cost, Distance, S, n);
}
void shortestPath01(int Cost[][10], int Distance[], bool S[], int n) { // From online(Lectures)...

    for(int i=0; i<n; i++) { // Setting all Distanceances to infinity and status to unvisited...
        Distance[i] = I;
        S[i] = false;
    }
    Distance[0] = 0; // Since no self loop...  
    
    for(int i=0; i<n; i++) {
        int minVertex = -1;
        for(int i=0; i<n; i++) {
            if(!S[i] && (minVertex == -1 || Distance[i] < Distance[minVertex])) {
                minVertex = i; 
            }
        }
        S[minVertex] = true;
        for(int j=0; j<n; j++) {
            if(Cost[minVertex][j] != 0 && !S[j]) {
                if(Distance[minVertex] + Cost[minVertex][j] < Distance[j]) {
                    Distance[j] = Distance[minVertex] + Cost[minVertex][j];
                }
            }
        }
    }
    displayContent(Cost, Distance, S, n);
}