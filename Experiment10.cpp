/* **********************************************************************************************************
Lab ID        : 10.0
Program Title : Sum of subsets Problem using Backtracking...
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      :   -05-2023 
Description   : Program to implement Sub of subsets problem using Backtracking...
------------------------------------------------------------------------------------------------------------
Input : No. of items, item(weights), total capacity...
        -> n = 4
        -> capacity = 25
        -> items(array/set) = 10 25 5 10
Output : 
        -> The Solution Vectors are : 
                1   0   1   1   
                0   1   0   0
------------------------------------------------------------------------------------------------------------
Algorithm     : -
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <iostream>
#include <cstring>

#define MAX 20

int n, capacity;
int set[MAX]; // Declare an array to store the input set

// Function to generate all the solution vectors recursively
void sumOfSubset(int sum, int item, int remainingCapacity, std::string solnVector) {

    if ((sum == capacity) && (remainingCapacity == 0)) { 
        // If the required sum is achieved and all elements have been used, print the solution vector
        std::cout << solnVector << std::endl;
    }
    if ((sum > capacity) || (remainingCapacity == 0)) { 
        // If the sum exceeds the required sum or no more elements are available, return 
        return;
    }
    // Recursively call the function to include and exclude the next element in the solution vector
    sumOfSubset(sum+set[item], item+1, remainingCapacity-set[item], solnVector + "1   "); // Include the current element
    sumOfSubset(sum, item+1, remainingCapacity-set[item], solnVector + "0   "); // Exclude the current element
}
int main()
{
    int totalSum = 0;   // Declare a variable to store the sum of all elements in the set
    std::string solnVector = ""; // Declare a string to store the current solution vector

    std::cout << "Enter no. of elements : ";
    std::cin >> n;
    std::cout << "Enter the elements in the set : ";
    for(size_t i{0}; i<n; i++) { // Input the set from the user and calculate the total sum
        std::cin >> set[i];
        totalSum += set[i];
    }
    std::cout << "Enter the Capacity : ";
    std::cin >> capacity;
    std::cout << std::endl << "The Solution Vectors are : " << std::endl;
    sumOfSubset(0, 0, totalSum, solnVector);
    return 0;
}