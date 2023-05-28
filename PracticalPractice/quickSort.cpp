#include <iostream>

void quickSort(int* A, int low, int high) {

    int start = low;
    int pivot = start;
    int end = high;

    if(low < high) {
        
        while(start < end) {

            while(A[start] <= A[pivot]) { start++; }
            while(A[end] > A[pivot]) { end--; }
            if(start < end) 
            {
                int temp = A[start];
                A[start] = A[end];
                A[end] = temp;
            }
        }
        int temp = A[pivot];
        A[pivot] = A[end];
        A[end] = temp;

        quickSort(A, low, end);
        quickSort(A, end+1, high);
    }
}
int main() {

    int n;
    std::cin >> n;

    int A[n];
    for(size_t i{0}; i<n; i++) {
        std::cin >> A[i];
    }
    quickSort(A, 0, n-1);

    for(size_t i{0}; i<n; i++) {
        std::cout <<A[i] << " ";
    }
    std::cout << std::endl;
    return(0);
}