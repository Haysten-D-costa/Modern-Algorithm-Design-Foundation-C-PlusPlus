# include <iostream>
# define INFINITY 9999

using namespace std;


bool S[10];
int n = 6, Dist[10];

int main()
{
    int v = 0, u, w;
    int Cost[10][10] = {
        {INFINITY, 50, 45, 10, INFINITY, INFINITY},
        {INFINITY, INFINITY, 10, 15, INFINITY, INFINITY},
        {INFINITY, INFINITY, INFINITY, INFINITY, 30, INFINITY},
        {20, INFINITY, INFINITY, INFINITY, 15, INFINITY},
        {INFINITY, 20, 35, INFINITY, INFINITY, INFINITY},
        {INFINITY, INFINITY, INFINITY, INFINITY, 3, INFINITY}
    };


    for(int i=0; i<n; i++) {
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
            int temp_cost_v = INFINITY; //setting for temporary use...
            for(int j=0; j<6; j++) { //SETS 'U' WRT 'V'...

                if((S[j] != true) && (Cost[v][j] < temp_cost_v)) 
                { 
                    temp_cost_v = Cost[v][j];
                    u = j; 
                }
            }
            counter++;
        }
        
        S[u] = true;
        
        int temp_cost_w = INFINITY;

        for(int k=0; k<n; k++) { //SETS 'U' WRT 'V'...
            if((S[k] != true) && (Cost[u][k] < temp_cost_w)) {
                temp_cost_w = Cost[u][k];
                w = k;
            }
        }
        if(Dist[w] > Dist[u] + Cost[u][w]) {
            Dist[w] = Dist[u] + Cost[u][w];
            cout << Dist[w] << endl;
        }
        cout << "w = " << w << " ; v = " << v << endl; 
    }
    for(int i=0; i<n; i++) {
        cout << "Distance from 0 -> " << i << " is " << Dist[i] << endl; 
    }
    return(0);
}