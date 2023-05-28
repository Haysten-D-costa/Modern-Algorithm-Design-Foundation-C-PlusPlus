#include <iostream>

int subString(std::string S1, int len1, std::string S2, int len2) {

    int flag = 0;
    for(int i=0; i<=len1-len2; i++) {

        int j = 0;
        while((j < len2) && (S2[j] == S1[j+i])) {
            j++;
        }
        if(j == len2) {
            int flag = 1;
            return i;
        }
    }
    if(!flag) { return -1; }
}
int main() {

    std::string S1, S2;
    std::cin >> S1 >> S2;

    int len1 = S1.length();
    int len2 = S2.length();
    int index = subString(S1, len1, S2, len2);

    std::cout << (index) << std::endl;
    return(0);
}