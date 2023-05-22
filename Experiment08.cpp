/* **********************************************************************************************************
Lab ID        : 8.0
Program Title : OPTIMAL Binary Search tree implementation...
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      :   -04-2023
------------------------------------------------------------------------------------------------------------
Description   : Program to implement OBST using dynamic programming.
Input         : -
Output        : Elements in bst, prob(Successful, unsuccessful search, weight matrix, costmatrix, ), cost.
Algorithm     : -
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <iostream>
#include <limits.h>
using namespace std;

int n = 4;
int p[10] = {2, 3, 1, 2};
int q[10] = {2, 2, 1, 1, 2};
int weight[10][10], cost[10][10], root[10][10];

void optimalBST();
int find(int i, int j);
void display(int A[][10], int n);

int main() {

    optimalBST();
    return(0);
}
void display(int A[][10], int n) {
    for(int i=0; i<=n; i++) 
    {
        for(int j=0; j<=n; j++) 
        {
            // cout << A[i][j] << " ";
            if(j < i) {
                cout << "-" << " ";
            }
            else {
                cout << A[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void optimalBST() {

    for(int i=0; i<n; i++) 
    {
        weight[i][i] = q[i];
        cost[i][i] = 0;
        root[i][i] = 0;

        weight[i][i+1] = q[i] + q[i+1] + p[i+1];
        root[i][i+1] = i + 1;
        cost[i][i+1] = q[i] + q[i+1] + p[i+1];
    }
    weight[n][n] = q[n];
    root[n][n] = 0;
    cost[n][n] = 0;

    // display(cost, n);
    // display(root, n);
    // display(weight, n);
    for(int m=2; m<=n; m++) {
        for(int i=0; i<=n-m; i++) 
        {
            int j = i + m;
            weight[i][j] = weight[i][j-1] + p[j] + q[j];

            int k = find(i, j);
            cost[i][j] = weight[i][j] + (cost[i][k-1] + cost[k][j]);
            root[i][j] = k;
            
            // display(weight, n); cout << endl;
            // display(cost, n); cout << endl;
            // display(root, n); cout << endl;
        }
    }
    display(weight, n); cout << endl;
    display(cost, n); cout << endl;
    display(root, n); cout << endl;
}
int find(int i, int j) {

    int l;
    int min = INT_MAX;
    for(int m=root[i][j-1]; m<=root[i+1][j]; ++m) 
    {
        if((cost[i][m-1] + cost[m][j]) < min) 
        {
            min = cost[i][m-1] = cost[m][j];
            l = m;
        }
    }
    return (l);
}