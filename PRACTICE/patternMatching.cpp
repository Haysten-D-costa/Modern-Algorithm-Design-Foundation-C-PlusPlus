#include <iostream>
#include <cstring>

int subString(std::string S1, std::string S2) {
    
    int len1 = S1.length();
    int len2 = S2.length();

    int flag = 0;
    for(int i{0}; i<=len1-len2; i++) {

        int j = 0;
        while((j < len2) && (S2[j] == S1[i + j])) { j++; }
        if(j == len2) {
            flag = 1;
            return i;
        }
    }
    return -1;
}

int main() {
    std::string S1;
    std::string S2;
    std::cin >> S1 >> S2;
    std::cout << subString(S1, S2);
    return 0;
}