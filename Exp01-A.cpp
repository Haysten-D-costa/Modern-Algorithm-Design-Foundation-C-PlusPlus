/* *****************************************************************************************************************
Lab ID        : 1.1(A)
Program Title : Binary Search using divide and conquer.
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      : --
--------------------------------------------------------------------------------------------------------------------
Description   : program to implement Binary Search using Divide and Conquer.(Method 01 : Iterative approach.)
Algorithm     : --
Prerequisites : C++
Known Bugs    : NONE
***************************************************************************************************************** */
#include <iostream>
using namespace std;

void display(int A[], int n); //Function to display the array...
void bubbleSort(int A[], int n); //Sorts the array in ascending order...
int binarySearch(int A[], int n); //Searches for required element, in recursive method...

int main()
{
    int n, A[100], found;
    cout << "Enter the no. of elements in the array : ";
    cin >> n;
    cout << "Enter '" << n << "' elements : ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    cout << endl;
    display(A, n);
    bubbleSort(A, n);
    cout << endl << "Sorted ";
    display(A, n);
    found = binarySearch(A, n);

    if(found == -1) { cout << endl << "No such element present !"; }
    else { cout << endl << "Element found at position '" << found+1 << "' (index " << found << ") !"; }
    return(0);
}
void bubbleSort(int A[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(A[j] > A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
int binarySearch(int A[], int n) {
    int key;
    int low = 0;
    int high = n-1;
    int mid = (low + high) / 2;
    cout << endl << "\nEnter value to be searched : ";
    cin >> key;

    while(low <= high) {
        mid = (low + high) / 2;
        if(key == A[mid]) { return(mid); }
        else if(key > A[mid]) { low = mid + 1; }
        else { high = mid - 1; }
    }
    return(-1);
}
void display(int A[], int n) {
    cout << "Array is : ";
    for(int i=0; i<n; i++) { cout << A[i] << "\t"; }
}
