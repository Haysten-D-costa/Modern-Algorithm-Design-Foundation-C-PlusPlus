/* **********************************************************************************************************
? Lab ID        : 9.0
? Program Title : Graph Colouring Algorithm...
? Author        : Haysten D'costa
? Roll No.      : 21co56
? Class         : Comp B[Batch P3]
? Language      : C++
? Due Date      :   -05-2023
------------------------------------------------------------------------------------------------------------
? Description   : Program to implement Graph colouring algorithm using backtracking....
? Input         :  
?       -> n = 4
?       -> m(colors) = 2
?       -> adjMatrix = 0 1 0 1
?                      1 0 1 0
?                      0 1 0 1
?                      1 0 1 0
? Output   : 
?       Possible solutions : 
?           ->  (  1  2  1  2  )
?           ->  (  2  1  2  1  )
? Algorithm     : -
? Prerequisites : Basics of C and C++
? Known Bugs    : NONE
*********************************************************************************************************** */
#include <iostream>
#define MAX 20
using namespace std;

int m = 3;   // no. of colors available for graph coloring...
int n = 4;   // Number of vertices in graph...
int x[MAX];  // Resultant vector (Gives the colours used for each vertex -i.e- the possible solutions)...

int Graph[MAX][MAX];    // Adjacency matrix (of the graph)....
void mColouring(int k); // Function to color the vertices, with possible colors...
void nextVertex(int k); // Function to select nodes to be colored...

int main() {
    int k = 0; // Vertex (starting from 0th vertex)...

    cout << endl << "Enter no. of verteces : "; cin >> n;
    cout << "Enter no. of colours possible : "; cin >> m;
    cout << endl << "Enter the adjacency matrix : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> Graph[i][j];
        }
    }
    mColouring(k); // k=0 -i.e- start colouring the graph from the 0th vertex...
    return(0);
}
void mColouring(int k) {

    while(1) 
    {
        int static counter = 0;
        nextVertex(k);
        if(x[k] == 0) { 
            return; 
        }
        if(k == n) {
            if(counter == 0) { 
                cout << endl << "Possible solutions : "; 
                counter ++; 
            }
            cout << endl << " ->  (  ";
            for(int i=0; i<n; i++) {
                cout << x[i] << "  ";
            }
            cout << ")";
            return;
        }
        else { 
            mColouring(k+1); 
        }
    }
}
void nextVertex(int k) {

    int j;
    while(1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0) { 
            return; 
        }
        for(j=0; j<n; j++) {
            if((Graph[k][j] == 1) && (x[k] == x[j])) { 
                break; 
            }
        }
        if(j == n) { 
            return; 
        }
    }
}
