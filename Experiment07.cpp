/* **********************************************************************************************************
Lab ID        : 7.0
Program Title : Longest Common SubSequence...
Author        : Haysten D'costa
Roll No.      : 21co56
Class         : Comp B[Batch P3]
Language      : C++
Due Date      :   -04-2023
------------------------------------------------------------------------------------------------------------
Description   : Program to implement Longest common subsequence algorithm...
Input         : Two strings to be compared...
Output        : LCS Matrix, LCS string and Length of string...
Algorithm     : -
Prerequisites : Basics of C and C++
Known Bugs    : NONE
********************************************************************************************************** */
#include <cstring>
#include <iostream>
using namespace std;

void longestCommonSequence(string S1, string S2, int len1, int len2)
{
    cout << endl << "-> String 1 : " << S1
         << endl << "-> String 2 : " << S2 << endl << endl;
    
    int LCS[len1 + 1][len2 + 1];

	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0)
				LCS[i][j] = 0;
			else if (S1[i - 1] == S2[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }

	int index = LCS[len1][len2]; // To keep track of index visited...

	// Create a character array to store the lcs string
	char lcs[index + 1];
	lcs[index] = '\0'; // Set the terminating character

	int i = len1, j = len2;
	while (i > 0 && j > 0) {
		// If current character in S1 and S2 are same, then current character is part of LCS
		if (S1[i - 1] == S2[j - 1]) {
			lcs[index - 1] = S1[i - 1]; // Put current character in result
			i--;
			j--;
			index--; 
		}
		else if (LCS[i - 1][j] > LCS[i][j - 1])
			i--;
		else
			j--;
	}
	cout << endl << "-> LCS of " << S1 << " and " << S2 << " is " << lcs;
    cout << endl << "-> Length of the longest common subsequence is : " << LCS[len1][len2] << endl << endl;
}
int main()
{
    string S1, S2;
    cout << "Enter two strings : "; 
    cin >> S1 >> S2;

    int len1 = S1.size();
    int len2 = S2.size();

	longestCommonSequence(S1, S2, len1, len2);
	return 0;
}