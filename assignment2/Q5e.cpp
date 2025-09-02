#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {2, 5, 6, 7},
        {3, 6, 8, 9},
        {4, 7, 9, 10}
    };

    int size = n*(n+1)/2; 
        int sym[size];
    int k = 0;

    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            sym[k++] = matrix[i][j];
        }
    }

    
    cout << "Stored Symmetric Matrix: ";
    for(int i=0; i<size; i++) cout << sym[i] << " ";
    cout << endl;

    // Reconstruct
    k = 0;
    int reconstruct[4][4];
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            reconstruct[i][j] = sym[k];
            reconstruct[j][i] = sym[k]; 
            k++;
        }
    }

    cout << "Reconstructed Matrix:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << reconstruct[i][j] << " ";
        }
        cout << endl;
    }
}
