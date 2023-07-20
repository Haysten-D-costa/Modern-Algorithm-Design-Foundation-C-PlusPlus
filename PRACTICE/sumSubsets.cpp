#include <iostream>
#define MAX 10

int n = 4;
int totalSum = 0;
int capacity = 25;
std::string solnVector = "";
int set[MAX] = {10, 5, 25, 10};

void sumOfSubsets(int sum, int item, int remCapacity, std::string solnVector) {
    if((sum == capacity) && (remCapacity == 0)) { std::cout << solnVector << std::endl; }
    if((sum >  capacity) || (remCapacity == 0)) { return; }

    sumOfSubsets(sum+set[item], item+1, remCapacity-set[item], solnVector+ "1  ");
    sumOfSubsets(sum, item+1, remCapacity-set[item], solnVector+"0  ");
}
int main() {
    for(auto i: set) {
        totalSum += i;
    }
    sumOfSubsets(0, 0, totalSum, solnVector);
    return 0;
}
