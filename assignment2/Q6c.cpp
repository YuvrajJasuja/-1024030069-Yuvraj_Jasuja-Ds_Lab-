#include <iostream>
using namespace std;


void multiplySparse(int A[][3], int B[][3], int C[][3]) {
    
    if (A[0][1] != B[0][0]) {
        cout << "Matrices cannot be multiplied!" << endl;
        return;
    }

    int m = A[0][2]; 
    int n = B[0][2]; 
    int k = 1;       

    
    C[0][0] = A[0][0];  
    C[0][1] = B[0][1];  

    
    int temp[100][3];
    int t = 0;


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i][1] == B[j][0]) { 
                int row = A[i][0];
                int col = B[j][1];
                int val = A[i][2] * B[j][2];

      
                bool found = false;
                for (int x = 0; x < t; x++) {
                    if (temp[x][0] == row && temp[x][1] == col) {
                        temp[x][2] += val;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    temp[t][0] = row;
                    temp[t][1] = col;
                    temp[t][2] = val;
                    t++;
                }
            }
        }
    }

    
    for (int i = 0; i < t; i++) {
        if (temp[i][2] != 0) { 
            C[k][0] = temp[i][0];
            C[k][1] = temp[i][1];
            C[k][2] = temp[i][2];
            k++;
        }
    }

    C[0][2] = k - 1;
}


void display(int M[][3]) {
    int total = M[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= total; i++) {
        cout << M[i][0] << "   " << M[i][1] << "   " << M[i][2] << endl;
    }
}

int main() {
    
    int A[5][3] = {
        {2, 3, 3},  
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3}
    };

    int B[5][3] = {
        {3, 2, 3},  
        {0, 1, 4},
        {1, 0, 5},
        {2, 1, 6}
    };

    int C[100][3]; 

    multiplySparse(A, B, C);

    cout << "Matrix A\n";
    display(A);
    cout << "\nMatrix b\n";
    display(B);
    cout << "\nMatrix C\n";
    display(C);

    return 0;
}
