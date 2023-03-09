/* **********************************************************************************************************
Lab ID        : 2.0
Program Title : Merge Sort using Divide and Conquer
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      : --
-----------------------------------------------------------------------------------------------------------------------------
Description   : Program to implement Merge Sort algorithm using Divide and Conquer...
Algorithm     : --
Prerequisites : C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <iostream>
using namespace std;

void display(int A[], int n);
void sort(int A[], int low, int up);
void mergeSort(int A[], int low, int mid, int up);

int n, A[10], B[10];

int main()
{
    cout << "Enter no. of elements in array : ";
    cin >> n;
    cout << endl << "Enter '" << n << "' elements : ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    cout << endl << "Unsorted Array : "; display(A, n);
    sort(A, 0, n-1);
    cout << endl << "Sorted Array   : "; display(A, n);
    cout << "\n\n";

    return(0);
}
void display(int A[], int n)
{
    for(int i=0; i<n; i++) {
        cout << A[i] << "\t";
    }
}
void sort(int A[], int low, int up)
{
    if(low < up) {
        int mid = (low + up)/2;
        sort(A, low, mid);
        sort(A, mid+1, up);
        mergeSort(A, low, mid, up);
    }
}
void mergeSort(int A[], int low, int mid, int up)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    while((i <= mid) &&(j <= up))
    {
        if(A[i] <= A[j]) {
            B[k] = A[i];
            i++; k++;
        }
        else {
            B[k] = A[j];
            j++; k++;
        }
    }
    if(i > mid) {
        while(j <= up) {
            B[k] = A[j];
            j++; k++;
        }
    }
    else {
        while(i <= mid) {
            B[k] = A[i];
            i++; k++;
        }
    }
    for(int i=low; i<=up; i++) {
        A[i] = B[i];
    }
}
