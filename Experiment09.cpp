/* **********************************************************************************************************
Lab ID        : 9.0
Program Title : Graph Colouring Algorithm...
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      :   -05-2023
------------------------------------------------------------------------------------------------------------
Description   : Program to implement Graph colouring algorithm using backtracking....
Input         : -
Output        : 
Algorithm     : -
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <iostream>
using namespace std;

void mColouring(int n, int m, int k, int x[], int Graph[][10]);
void nextVertex(int n, int m, int k, int x[], int Graph[][10]);

int main() {

    int k = 1; //? Vertex visit(count)...
    int m = 2; //? Max colours assigned...
    int n = 4; //? Number of vertices in graph...
    //todo cout << endl << "Enter no. of verteces : "; cin >> no_vertices;

    int x[10]; //? Resultant vector (gives the colours used for each vertex)...
    
    int Graph[10][10] = { //? Matrix form of the graph....
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };

    mColouring(n, m, k, x, Graph);
    return(0);
}
void mColouring(int n, int m, int k, int x[], int Graph[][10]) {

    while(1) 
    {
        nextVertex(n, m, k, x, Graph);
        if(x[k] == 0) { return; }
        if(k == n) {

            cout << endl << "Result Vector : (  ";
            for(int i=0; i<n; i++) {
                cout << x[i] << "  ";
            }
            cout << ")";
        }
        else { mColouring(n, m, k+1, x, Graph); }
    }
}
void nextVertex(int n, int m, int k, int x[], int Graph[][10]) {

    int j;
    while(1)
    {
        x[k] = (x[k] + 1) % (m+1);
        if(x[k] == 0) { return; }

        for(j=0; j<n; j++) {
            if((Graph[k][j] == 1) && (x[k] == x[j])) { break; }
        }
        if(j == (n+1)) { return; }
    }
}
