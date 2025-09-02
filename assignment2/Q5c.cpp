#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int matrix[4][4] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };

    int size = n*(n+1)/2; 
    int lower[size];
    int k = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            lower[k++] = matrix[i][j];
        }
    }

    cout << "Stored Lower Triangle: ";
    for(int i=0; i<size; i++) cout << lower[i] << " ";
    cout << endl;

    //Reconstruct
    k = 0;
    int reconstruct[4][4] = {0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            reconstruct[i][j] = lower[k++];
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
