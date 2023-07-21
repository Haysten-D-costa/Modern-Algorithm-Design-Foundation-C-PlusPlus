/* *****************************************************************************************************************
Lab ID        : 1.1(A)
Program Title : Binary Search using divide and conquer.
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++ 
Due Date      : --
--------------------------------------------------------------------------------------------------------------------
Description   : program to implement Binary Search using Divide and Conquer.(Method 02 : Recursive approach.)
Algorithm     : --
Prerequisites : C++
Known Bugs    : NONE
***************************************************************************************************************** */
#include <iostream>
using namespace std;

void display(int A[], int n); //Function to display the array...
void bubbleSort(int A[], int n); //Sorts the array in ascending order...
int binarySearch(int A[], int low, int high, int key); //Searches for required element, in iterative method...

int main()
{
    int n, key, A[100], found;
    int low, high;
    cout << "Enter the no. of elements in the array : ";
    cin >> n;
    cout << "Enter '" << n << "' elements : ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    low = 0; high = n-1;
    cout << endl;
    display(A, n);
    bubbleSort(A, n);

    cout << endl << "Sorted ";
    display(A, n);
    cout << endl << "\nEnter value to be searched : ";
    cin >> key;
    found = binarySearch(A, low, high, key);

    if(found == -1) { cout << endl << "No such element present !"; }
    else { cout << endl << "Element found at position '" << found+1 << "' (index " << found << ") !"; }
    cout << endl;
    return(0);
}

void display(int A[], int n) {
    cout << "Array is : \n";
    for(int i=0; i<n; i++) { cout << A[i] << "\t"; }
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
int binarySearch(int A[], int low, int high, int key) {

    if(low > high) {
        return(-1);
    }
    int mid = (low + high) / 2;
    if(key == A[mid]) { return(mid); }
    else if(key > A[mid]) { binarySearch(A, mid+1, high, key); }
    else { binarySearch(A, low, mid-1, key); }
}
