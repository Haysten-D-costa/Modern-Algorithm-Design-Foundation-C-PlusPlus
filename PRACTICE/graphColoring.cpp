#include <iostream>
#define MAX 10
 
int m = 2;
int n = 4;
int x[MAX] {0};
int Graph[MAX][MAX] = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0}
};
void nextVertex(int k) {
    while(1) {
        int j;
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0) return;

        for(j=0; j<n; j++) {
            if((Graph[k][j] == 1) && (x[k] == x[j])) {
                break;
            }
        }
        if(j == n) return;
    }
}
void mColoring(int k) {
    while(1) {

        nextVertex(k);
        if(x[k] == 0) return;
        if(k == n) {
            for(int i{0}; i<n; i++) {
                std::cout << x[i] << " ";
            }
            std::cout << std::endl;
            return;
        }
        else mColoring(k + 1);
    }
}
int main() {
    int k = 0;
    mColoring(k);

    return 0;
}