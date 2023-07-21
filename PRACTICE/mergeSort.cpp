#include <iostream>
#define MAX 20
 
void mergeSort(int* A, int low, int high) {
    if(low < high) 
    {
        int mid = (low + high)/2;

        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}
void merge(int* A, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int tempArray[MAX];

    while((i <= mid) && (j <= high)) {
        if(A[i] <= A[j]) {
            tempArray[k] = A[i];
            i++; k++;
        }
        else {
            tempArray[k] = A[j];
            j++; k++;
        }
    }
    while(i <= mid) {
        tempArray[k] = A[i];
        i++; k++;
    }
    while(j <= high) {
        tempArray[k] = A[j];
        j++; k++;
    }
    for(int i{low}; i<=high; i++) {
        A[i] = tempArray[i];
    }
}
int main() {
    int n;
    std::cin >> n;
    int A[MAX];
    for(int i{0}; i<n; i++) { 
        std::cin >> A[i]; 
    }
    mergeSort(A, 0, n-1);

    for(int i{}; i<n; i++) {
        std::cout << A[i] << " ";
    }
    return 0;
}