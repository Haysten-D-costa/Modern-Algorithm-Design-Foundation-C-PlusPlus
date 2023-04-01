# include <iostream>
# define I 9999 // Infinity value...

using namespace std;

void shortestPath(int Cost[][10], int Dist[], bool S[], int n);   // Function to find shortest path from initial node(0) to others...
void displayContent(int Cost[][10], int Dist[], bool S[], int n); // Function to display the Cost, Distance and Status (matrx and arrays)....

int main()
{
    bool S[10];
    int n = 8, Dist[10];
    // int Cost[10][10] = { /* Matrix : Example '01' Given by teacher...*/
    //     {I , 50, 45, 10, I , I },
    //     {I , I , 10, 15, I , I },
    //     {I , I , I , I , 30, I },
    //     {20, I , I , I , 15, I },
    //     {I , 20, 35, I , I , I },
    //     {I , I , I , I , 3 , I }
    // };

    // int Cost[10][10] = { /* Matrix : Example '02' Simply created...*/
    // /*    0  1  2  3  4  5  6 */ 
    // /*0*/{I, 3, I, 2, I, I, I },
    // /*1*/{I, I, 2, I, I, I, I },
    // /*2*/{I, I, I, I, I, I, 1 }, 
    // /*3*/{1, I, I, I, 1, I, I },
    // /*4*/{I, 5, I, 2, I, 3, I },
    // /*5*/{I, I, 5, I, 6, I, I },
    // /*6*/{I, I, I, I, I, 2, I }
    // };

    int Cost[10][10] = {  /* matrix : Example '03' Given by math sir...*/
        {I , 8 , 2 , 5 , I , I , I , I }, 
        {8 , I , I , 2 , I , 13, I , I }, 
        {2 , I , I , 2 , 5 , I , I , I }, 
        {5 , 2 , 2 , I , 1 , 6 , 3 , I },
        {I , I , 5 , 1 , I , I , 1 , I }, 
        {I , 13, I , 6 , I , I , 2 , 3 },
        {I , I , I , 3 , 1 , 2 , I , 6 },
        {I , I , I , I , I , 3 , 6 , I }
    };

    shortestPath(Cost, Dist, S, n); // Calls function to find the shortest paths...
    cout << endl << endl;

    return(0);
}

void shortestPath(int Cost[][10], int Dist[], bool S[], int n) 
{
    int v = 0, u, w; //Node -i.e- Vertice pointers...

    for(int i=0; i<n; i++) { // Initialization of 'S' and 'Dist'(-using Cost matrix) arrays...
        S[i] = false;
        Dist[i] = Cost[v][i];
    }
    S[v] = true; // Sets first node as visited -i.e- TRUE...
    Dist[v] = 0;

    // MAIN PROCEDURE (FINDING SHORTEST PATH)....
    for(int i=1; i<n; i++) {
        u = w;
        static int counter = 0;
        if(counter == 0) {
            int temp_cost_v = I; // Setting for temporary use...
            for(int j=0; j<n; j++) { // Sets 'u' wrt 'v'...

                if((S[j] != true) && (Cost[v][j] < temp_cost_v)) 
                { 
                    temp_cost_v = Cost[v][j];
                    u = j; 
                }
            }
            counter++;
        }
        S[u] = true;
        
        int temp_cost_w = I; // Setting for temporary use...
        for(int k=0; k<n; k++) { // Sets 'w' wrt 'u'...
            if((S[k] != true) && (Cost[u][k] < temp_cost_w)) {
                temp_cost_w = Cost[u][k];
                w = k;
            }
        }
        if(Dist[w] > Dist[u] + Cost[u][w]) {
            Dist[w] = Dist[u] + Cost[u][w];
            cout << endl << "Edited shortest distance : " << Dist[w] << "  ";
        }
        cout << " { w = " << w << " ; u = " << u << " ; v = " << v << " }"; // Displaying the nodes selected as 'u' and 'w'...
    }
    displayContent(Cost, Dist, S, n);
}
void displayContent(int Cost[][10], int Dist[], bool S[], int n)
{
    cout << endl << endl << "MAT ";
    for(int i=0; i<n; i++) { cout << "  [" << i << "]"; } cout << endl << endl;
    for(int i=0; i<n; i++) { // To display the Cost matrix...
        cout << "[" << i << "]   ";
        for(int j=0; j<n; j++) {
            if(Cost[i][j] == 9999) { cout << "**   "; }
            else if(Cost[i][j] < 10) { cout << "0" << Cost[i][j] << "   "; }
            else { cout << Cost[i][j] << "   "; }
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0; i<n; i++) { // To display the Distance array...
        cout << "Shortest Path from 0 -> " << i << " : " << Dist[i] << endl; 
    }
    cout << endl;
    for(int i=0; i<n; i++) { // To display the Status array...
        cout << "Status '" << i << "' : " << S[i] << endl; 
    }
    cout << endl << endl;
}