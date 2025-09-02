#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {0, 5, 6, 7},
        {0, 0, 8, 9},
        {0, 0, 0, 10}
    };

    int size = n*(n+1)/2;
    int upper[size];
    int k = 0;


    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            upper[k++] = matrix[i][j];
        }
    }

    
    cout << "Stored Upper Triangle: ";
    for(int i=0; i<size; i++) cout << upper[i] << " ";
    cout << endl;

    // Reconstruct
    k = 0;
    int reconstruct[4][4] = {0};
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            reconstruct[i][j] = upper[k++];
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
