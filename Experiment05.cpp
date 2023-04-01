# include <iostream>
# define I 9999 // Infinity value...

using namespace std;
void shortestPath(int Cost[][10], int Dist[], bool S[], int n);




int main()
{
    bool S[10];
    int n = 6, Dist[10];

    int Cost[10][10] = { /* Matrix : Example '01' Given by teacher...*/
        {I , 50, 45, 10, I , I },
        {I , I , 10, 15, I , I },
        {I , I , I , I , 30, I },
        {20, I , I , I , 15, I },
        {I , 20, 35, I , I , I },
        {I , I , I , I , 3 , I }
    };
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
    shortestPath(Cost, Dist, S, n);
    cout << endl << endl;
    return(0);
}
void shortestPath(int Cost[][10], int Dist[], bool S[], int n) 
{
    int v = 0, u, w; //Node -i.e- Vertice pointers...

    for(int i=0; i<n; i++) { // Sets all nodes to be un-visited and Distance according to Cost...
        S[i] = false;
        Dist[i] = Cost[v][i];
    }
    S[v] = true;
    Dist[v] = 0;

    for(int i=0; i<n; i++) { // To display the Cost matrix...
        for(int j=0; j<n; j++) {
            cout << Cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    for(int i=0; i<n; i++) { // To display the Distance array...
        cout << "Distance from 0 -> " << i << " : " << Dist[i] << endl; 
    }
    cout << endl;
    for(int i=0; i<n; i++) { // To display the Status array...
        cout << "Status : " << S[i] << endl; 
    }
    cout << endl << endl;

    // MAIN PROCEDURE (FINDING SHORTEST PATH)....
    for(int i=1; i<n; i++) {
        u = w;
        static int counter = 0;
        if(counter == 0) {
            int temp_cost_v = I; // Setting for temporary use...
            for(int j=0; j<6; j++) { // Sets 'u' wrt 'v'...

                if((S[j] != true) && (Cost[v][j] < temp_cost_v)) 
                { 
                    temp_cost_v = Cost[v][j];
                    u = j; 
                }
            }
            counter++;
        }
        
        S[u] = true;
        
        int temp_cost_w = I;

        for(int k=0; k<n; k++) { // Sets 'w' wrt 'u'...
            if((S[k] != true) && (Cost[u][k] < temp_cost_w)) {
                temp_cost_w = Cost[u][k];
                w = k;
            }
        }
        if(Dist[w] > Dist[u] + Cost[u][w]) {
            Dist[w] = Dist[u] + Cost[u][w];
            cout << Dist[w] << endl;
        }
        cout << "w = " << w << " ; v = " << v << endl; // Displaying the nodes selected as 'u' and 'w'...
    }
    cout << endl << endl;
    for(int i=0; i<n; i++) { // To display the Distance array...
        cout << "Distance from 0 -> " << i << " : " << Dist[i] << endl; 
    }
    cout << endl;
    for(int i=0; i<n; i++) { // To display the Status array...
        cout << "Status : " << S[i] << endl; 
    }
}