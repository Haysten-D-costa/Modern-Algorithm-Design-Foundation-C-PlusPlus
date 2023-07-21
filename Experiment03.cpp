/* **********************************************************************************************************
Lab ID        : 3.0
Program Title : Quick Sort Algorithm
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      : 00-03-2023
Description   : Program to implement Quick sort algorithm...
------------------------------------------------------------
Input  :
    -> n = 5
    -> array = 8 0 6 2 4 
Output : 
    Unsorted Array : 8      0       6       2       4
    Sorted Array   : 0      2       4       6       8
------------------------------------------------------------
Algorithm     : -
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <iostream>
using namespace std;

void display(int A[], int n);
void quickSort(int A[], int low, int high);

int main()
{
    int n, A[100];
    int low, high;
    cout << "Enter the no. of elements in the array : ";
    cin >> n;
    cout << "Enter '" << n << "' elements : ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    low = 0, high = n-1;
    cout << endl << "Unsorted Array : "; display(A, n);
    quickSort(A, 0, n-1);
    cout << endl << "Sorted Array   : "; display(A, n);

    return(0);
}

void display(int A[], int n) 
{
    for(int i=0; i<n; i++) { cout << A[i] << "\t"; }
}
void quickSort(int A[], int low, int high)
{
    if(low < high) 
    {
        int start = low;
        int pivot = start;
        int endd = high;
        while(start < endd)
        {
            while(A[start] <= A[pivot]) { start++; }
            while(A[endd] > A[pivot]) { endd--; }
            if(start < endd)
            {
                int tmp = A[start];
                A[start] = A[endd];
                A[endd] = tmp;
            }
        }
        int tmp = A[pivot];
        A[pivot] = A[endd];
        A[endd] = tmp;
        
        quickSort(A, low, endd-1);
        quickSort(A, endd+1, high);
    }
}