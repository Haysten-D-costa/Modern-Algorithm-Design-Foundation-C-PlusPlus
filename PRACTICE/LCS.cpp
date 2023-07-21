#include <iostream>

int LCS[10][10] {0};
void findString(int LCS[][10], std::string S1, std::string S2, int len1, int len2) {

    int index = LCS[len1][len2]; 
	char lcs[index + 1];
	lcs[index] = '\0'; 

	int i = len1;
    int j = len2;
	
    while (i > 0 && j > 0) {
		
        if (S1[i - 1] == S2[j - 1]) {
			lcs[index - 1] = S1[i - 1];
			i--;
			j--;
			index--; 
		}
		else if (LCS[i - 1][j] > LCS[i][j - 1])
			i--;
		else
			j--;
	}
    std::cout << lcs << std::endl;
}   
void longestCS(std::string S1, std::string S2) {
    int len1 = S1.length();
    int len2 = S2.length();

    for(int i{0}; i<=len1; i++) {
        for(int j{0}; j<=len2; j++) {

            if((i == 0) || (j == 0)) { LCS[i][j] = 0; }
            else if(S1[i-1] == S2[j-1]) { LCS[i][j] = LCS[i-1][j-1] + 1; }
            else { LCS[i][j] = std::max(LCS[i-1][j], LCS[i][j-1]); }

            std::cout << LCS[i][j] << " ";
        }
        std::cout << std::endl;
    }
    findString(LCS, S1, S2, len1, len2);
}
int main() {
    std::string S1, S2;
    std::cin >> S1 >> S2;
    longestCS(S1, S2);
    return 0;
}