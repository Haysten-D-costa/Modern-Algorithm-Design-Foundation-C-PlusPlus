/* **********************************************************************************************************
Lab ID        : 4.0
Program Title : Pattern Matching Algorithm
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      :   -04-2023 
-------------------------------------------------------------------------------------------------------------
Description   : Program to implement Pattern matching algorithm to check whether a given string contains a sub-string..
Input         : 
                S1 = HAYSTEN and S2 = TEN
Output        : Matched at index '4'
Algorithm     : -
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
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
    std::cout << "Enter two strings : ";
    std::cin >> S1 >> S2;
    std::cout << std::endl << "Matched at index  : " << subString(S1, S2);
    return 0;
}