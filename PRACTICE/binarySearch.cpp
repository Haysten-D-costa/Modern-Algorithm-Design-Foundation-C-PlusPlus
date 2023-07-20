#include <iostream>

int* sort(int *A, int n) {

    for(size_t i{1}; i<n; i++) {
        for(size_t j{0}; j<n-i; j++) {
            if(A[j] > A[j+1]) 
            {
                int temp{A[j]};
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return A;
}
void binarySearch_Ite(int A[], int low, int up, int search) {

    while(low <= up) {
        int mid = (low + up)/2;
        if(search == A[mid]) { std::cout << "Found at position " << (mid + 1) << ", (index " << (mid) << ")"; return; }
        else if(search < A[mid]) { up = mid-1; }
        else { low = mid+1; }
    }
    std::cout << "No such element found !" << std::endl;
}
void binarySearch_Rec(int* A, int low, int up, int search) {

    if(low > up) { 
        std::cout << "No such element found !" << std::endl; 
        return; 
    }
    int mid = (low + up)/2;
    if(search == A[mid]) { std::cout << "Found at position" << (mid + 1) << " (index " << mid << ")" << std::endl; }
    else if(search < A[mid]) { binarySearch_Rec(A, low, mid-1, search); }
    else { binarySearch_Rec(A, mid+1, up, search); }
}

int main() {
    int n = 5;
    int A[n] = {8, 2, 6, 0, 4};
    std::cout << std::endl;
    binarySearch_Rec(sort(A, n), 0, n-1, 2);

    return 0;
}