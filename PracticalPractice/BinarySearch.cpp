#include <iostream>

int* sort(int* A, int n) 
{
    for(size_t i{1}; i<=n; i++) {
        for(size_t j{0}; j<n; j++) {
            if(A[j] > A[j+1]) 
            {
                int temp {A[j]};
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return A;
}
void display(int* A, int n) 
{
    for(size_t i{0}; i<n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
void binarySearch_Recursive(int* A, int low, int up, int key);
void binarySearch_Iterative(int* A, int low, int up, int key);

int main() {

    int n = 5;
    int A[n] = {8, 0, 4, 2, 6};
    display(sort(A, n), n);
    binarySearch_Iterative(A, 0, n-1, 10);
    // binarySearch_Recursive(A, 0, n-1, 0);

    return 0;
}
void binarySearch_Iterative(int* A, int low, int up, int key) {
    
    int count{0};
    while(low <= up) {

        int mid = (low + up) / 2;
        if(key == A[mid]) {
            count++;
            std::cout << "Element '" << key << "' found at position " << mid + 1 << " (Index " << mid << ") "<< std::endl;
            break;
        }
        else if(key < A[mid]) {
            up = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if(count == 0) { std::cout << "No such element found ! " << std::endl; }
}
void binarySearch_Recursive(int* A, int low, int up, int key) {

    int count{0};
    if(low > up) {
        std::cout << "No such element found ! " << std::endl;
        return;
    }
    int mid = (low + up) / 2;
    if(key == A[mid]) {
        std::cout << "Element found at position " << mid + 1 << " (index " << mid << ")" << std::endl;
    }
    else if(key < A[mid]) {
        binarySearch_Recursive(A, low, mid-1, key);
    }
    else {
        binarySearch_Recursive(A, mid+1, up, key);
    }
}