#include <iostream> 
#define MAX 10

int max(int value1, int value2) {
    return((value1 > value2) ? value1 : value2);
}
void knapsack(int T[][MAX], int weight[], int profit[], int capacity, int n);
void select_items(int T[][MAX], int weight[], int profit[], int capacity, int n);

int main() {
    int n = 4;
    int capacity = 5;
    int weight[MAX] = {0, 2, 1, 3, 2};
    int profit[MAX] = {0, 12, 10, 20, 15};
    int T[MAX][MAX] {0};

    knapsack(T, weight, profit, capacity, n);
    return 0;
}
void knapsack(int T[][MAX], int weight[], int profit[], int capacity, int n) {
    for(int i{0}; i<=n; i++) {
        for(int j{0}; j<=capacity; j++) {
            if((i == 0) || (j == 0)) { T[i][j] = 0; }
            else if(weight[i] > j) { T[i][j] = T[i-1][j]; }
            else { T[i][j] = max(T[i-1][j], profit[i] + T[i-1][j-weight[i]]); }
            
            std::cout << T[i][j] << " ";
        }
        std::cout << std::endl;
    }
    select_items(T, weight, profit, capacity, n);
}

void select_items(int T[][MAX], int weight[], int profit[], int capacity, int n) {
    int i = n;
    int j = capacity;
    bool solution[MAX];

    while((i > 0) && (j > 0)) {
        if(T[i-1][j] != T[i][j]) {
            solution[i] = true;
            std::cout << "Added item " << i << std::endl; 
            j -= weight[i];
            i -= 1;
        }
        else {
            solution[i] = false;
            i -= 1;
        }
    }
    std::boolalpha;
    std::cout << "Solution : ";
    for(int i{1}; i<=n; i++) { 
        std::cout << solution[i] << " "; 
    }
}
