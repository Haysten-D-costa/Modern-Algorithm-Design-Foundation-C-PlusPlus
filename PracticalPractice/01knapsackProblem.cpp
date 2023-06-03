#include <iostream>
#define MAX 10

int max(int item1, int item2) {
    return((item1 > item2) ? item1 : item2);
}
void knapSack(int T[][MAX], int weight[], int profit[], int capacity, int no_items);
void selectItem(int T[][MAX], int weight[], int profit[], int capacity, int no_items);

int main() {

    int n = 4;
    int capacity = 5;
    int weight[MAX] = {0, 2, 1, 3, 2};
    int profit[MAX] = {0, 12, 10, 20, 15};
    int T[MAX][MAX] {0};

    knapSack(T, weight, profit, capacity, n);
    return(0);
}

void knapSack(int T[][MAX], int weight[], int profit[], int capacity, int no_items) {

    std::cout << "Knapsack table : " << std::endl;

    for(size_t i{0}; i<=no_items; i++) {
        for(size_t j{0}; j<=capacity; j++) {

            if((i == 0) || (j == 0)) { T[i][j] = 0;}
            else if(weight[i] > j) { T[i][j] = T[i-1][j]; }
            else { T[i][j] = max(T[i-1][j], T[i-1][j-weight[i]] + profit[i]); }

            std::cout << T[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    selectItem(T, weight, profit, capacity, no_items);
}
void selectItem(int T[][MAX], int weight[], int profit[], int capacity, int no_items) {

    int i = no_items;
    int j = capacity;
    bool solution[MAX] {false};

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
    std::cout << "Max Profit gain  : " << T[no_items][capacity] << std::endl
              << "Optimal solution : " << std::endl; 

    std::cout << "(";
    for(size_t i{1}; i<=no_items; i++) {
        std::cout << "\t" << solution[i];
    }
    std::cout << "\t)" << std::endl;
    
}