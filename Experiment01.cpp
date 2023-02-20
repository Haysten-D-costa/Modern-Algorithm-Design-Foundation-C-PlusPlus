/* To write a program to implement a binary search, (when array is not sorted) */
#include <iostream>
using namespace std;

const int size = 20;

void display(int A[], int n); //Function displays the elements of the array passed to it...
void bubbleSort(int A[], int n); //Function sorts the elements of the array passed, to apply binary search...
int binarySearchRec(int A[], int low, int up, int search); //Searches for requested array using a 'Recursive approach'...
int binarySearchIte(int A[], int low, int up, int search); //Searches for requested array using a 'Iterative approach'...

int main()
{
     int n, up, low, search, A[size], searchChoice;
     cout << endl << "Enter the no. of elements : ";
     cin >> n;
     cout << "Enter '" << n << "' elements : ";
     for(int i=0; i<n; i++) {
          cin >> A[i];
     }
     low = 0; 
     up = n-1;
     cout << endl << "Unsorted Array you entered : ";
     display(A, n);  //Displaying just to check saved values, in array...
     bubbleSort(A, n);  
     cout << endl << "Sorted Array : ";
     display(A, n);  //Displaying just to check -i.e- display whether the array is sorted...

     cout << endl << "\n1 -> To search using BS 'Recursive method' "
          << endl << "2 -> To search using BS 'Iterative method' "
          << endl << endl << "   ...Enter your choice : "; 
     cin >> searchChoice;
     switch(searchChoice) 
     {
          case 1: {
               cout << endl << "      Enter element to be searched : ";
               cin >> search;
               int found = binarySearchRec(A, low, up, search); 
               if(found == -1) { cout << endl << "No such element found !"; }
               else{ cout << endl << "Element found at position "<< found+1 << "(index " << found << ")"; }
          }break;
          case 2: {
               cout << endl << "      Enter element to be searched : ";
               cin >> search;
               int found = binarySearchRec(A, low, up, search); 
               if(found == -1) { cout << endl << "No such element found !"; }
               else{ cout << endl << "Element found at position "<< found+1 << "(index " << found << ")"; }
          }break;
          default: cout << endl << "Invalid choice for search entered !"; 
     }

     return(0);
}
void display(int A[], int n) 
{
     for(int i=0; i<n; i++) {
          cout << A[i] << "\t";
     }
}
void bubbleSort(int A[], int n) 
{
     for(int i=0; i<n; i++) {
          for(int j=0; j<n-1-i; j++) {
               if(A[j] > A[j+1]) 
               {
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
               }
          }
     }
}
int binarysearchIte(int A[], int low, int up, int search) 
{
     int mid = (low + up)/2;
     while(low <= up) 
     {
          mid = (low + up)/2;
          if(search == A[mid]) { return(mid); }
          else if(search < A[mid]) { up = mid-1; }
          else { low = mid+1; }
     }
     return(-1);
}
int binarySearchRec(int A[], int low, int up, int search)
{
     if(low > up) { return(-1); }
     int mid = (low + up)/2;
     if(search == A[mid]) { return(mid); }
     else if(search < A[mid]) { binarySearchRec(A, low, mid-1, search); }
     else { binarySearchRec(A, mid+1, up, search); }
}