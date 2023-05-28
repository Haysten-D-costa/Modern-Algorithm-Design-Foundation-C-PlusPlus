#include <iostream>

void merge(int* A, int low, int mid, int high) {

    int i = low;
    int j = mid + 1;
    int k = low;

    int n = ((sizeof(A))/(sizeof(A[0])));
    int tempArr[n];

    while((i <= mid) && (j <= high)) {
    
        if(A[i] <= A[j]) {
            tempArr[k] = A[i];
            i++; k++;
        }
        else {
            tempArr[k] = A[j];
            j++; k++;
        }
    }
    while(i <= mid) {
        tempArr[k] = A[i];
        i++; k++;
    }
    while(j <= high) {
        tempArr[k] = A[j];
        j++; k++;
    }
    for(int i{low}; i<=high; i++) {
        A[i] = tempArr[i];
    }
}
void mergeSort(int* A, int low, int high) {

    for(int i{low}; i<=high; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    if(low < high) {
        
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);

        merge(A, low, mid, high);
    }
}

int main() {

    int n;
    std::cin >> n;

    int A[n];
    for(size_t i{0}; i<n; i++) {
        std::cin >> A[i];
    }
    mergeSort(A, 0, n-1);

    for(size_t i{0}; i<n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return(0);
}