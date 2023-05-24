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
#define INFINITY 999
#define MAX 20

int n; // Number of nodes
int W[MAX][MAX]; // Weight matrix
int C[MAX][MAX]; // Cost matrix
int R[MAX][MAX]; // Root matrix
int P[MAX];      // Probabilities of successful search
int Q[MAX];      // Probabilities of unsuccessful search

// Function to print a matrix
void display(int matrix[MAX][MAX])
{
    for (size_t i{0}; i<=n; i++) {
        for (size_t j{i}; j<=n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void optimalBST()
{
    int min, min_preorderIndex;
    // Initialization
    for (size_t i{0}; i<=n; i++) {
        W[i][i] = Q[i];
        C[i][i] = 0;
        R[i][i] = 0;
    }
    // I-Weighted Matrix
    for (size_t i{1}; i<=n; i++) {
        for (size_t j{0}; j<=n-i; j++) {
            
            W[j][j+i] = P[j+i-1] + Q[j+i] + W[j][j+i-1]; // Calculate the weight of the sub-tree rooted at node j
        }
    }
    // II-Cost Matrix and Root Matrix
    for (size_t i{1}; i<=n; i++) {
        for (size_t j{0}; j<=n-i; j++) {
            
            min = INFINITY;
            for (size_t k{j+1}; k<=j+i; k++) {
                
                // Find the minimum cost of all possible sub-trees rooted at node j
                if (C[j][k-1] + C[k][j+i] < min) {
                    min = C[j][k-1] + C[k][j+i];
                    min_preorderIndex = k;
                }
            }
            C[j][j+i] = min + W[j][j+i]; // Calculate the cost of the sub-tree rooted at node j
            R[j][j+i] = min_preorderIndex; // Record the root of the sub-tree rooted at node j
        }
    }
    // Print the weight, cost, and root matrices
    std::cout << std::endl << "-> Weight Matrix : " << std::endl; display(W);
    std::cout << "-> Cost Matrix : " << std::endl; display(C);
    std::cout << "-> Root Matrix : " << std::endl; display(R);
    std::cout << "-> Final Cost is : " << C[0][n] << std::endl;
}
int main()
{
    std::cout << std::endl << "Enter no. of nodes in BST : ";
    std::cin >> n;
    std::cout << "Enter the Probabilities of Successful Search : ";
    for (size_t i{0}; i<n; i++) {
        std::cin >> P[i];
    }
    std::cout << "Enter the Probabilities of Unsuccessful Search : ";
    for (size_t i{0}; i<=n; i++) {
        std::cin >> Q[i];
    }
    optimalBST();

    return 0;
}