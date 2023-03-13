#include <iostream>
using namespace std;

void display(char A[], int n);
void searchString(char A[], char B[], int n, int m);

int main()
{
    int n, m;
    char A[100], B[100];
    cout << endl << "Enter the size of main array : "; cin >> n;
    cout << "Enter '" << n << "' characters for the main array : ";
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }
    cout << endl << "Enter the size of string to be searched : "; cin >> m;
    cout << "Enter '" << m << "' characters for the search string : ";
    for(int i=0; i<m; i++) {
        cin >> B[i];
    }
    cout << endl << "Main array    : "; display(A, n); cout << "\n";
    cout << "Search string : "; display(B, m);
    cout << "\n\n";
    searchString(A, B, n, m);

    return(0);
}

void display(char String[], int range) {
    for(int i=0; i<range; i++) { cout << String[i] << "\t"; }
}
void searchString(char A[], char B[], int n, int m) {
    int found = 0;
    
    for(int i=0; i<=n-m; i++) 
    {
        int j = 0;
        while((j < m) && (B[j] == A[i+j])) {
            j++;
        }
        if(j == m) {
            cout << "String found at position '" << i+1 << "' (Index " << i << ")" << endl;
            found = 1;
        }
    }
    if(found != 1) {
        cout << endl << "No such string found in main array... " << endl;
    }
}