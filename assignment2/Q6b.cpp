#include <iostream>
using namespace std;

void display(int s[][3]) {
    int terms = s[0][2];
    for (int i = 0; i <= terms; i++) {
        cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << endl;
    }
    cout << endl;
}


void addSparse(int A[][3], int B[][3], int C[][3]) {
    // Check if dimensions match
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices cannot be added!" << endl;
        return;
    }

    int i = 1, j = 1, k = 1;
    int m = A[0][2], n = B[0][2]; // non-zeros in A and B

    // Set metadata (rows, cols same; non-zeros will be filled later)
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    // Traverse both matrices
    while (i <= m && j <= n) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            // Same position → add values
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
        else if (A[i][0] < B[j][0] || 
                (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            // A’s element comes first
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
            k++;
        }
        else {
            // B’s element comes first
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
            k++;
        }
    }

    // Copy remaining elements of A
    while (i <= m) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    // Copy remaining elements of B
    while (j <= n) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }

    // Store number of non-zeros
    C[0][2] = k - 1;
}

int main() {
    
    int A[5][3] = {
        {3, 3, 3},   
        {0, 0, 1},
        {1, 1, 7},
        {2, 2, 5}
    };

    // B (3x3)
    int B[5][3] = {
        {3, 3, 3}, 
        {0, 0, 4},
        {1, 2, 6},
        {2, 2, 2}
    };

    int C[10][3];

    cout << "Matrix A\n";
    display(A);

    cout << "Matrix B\n";
    display(B);

    addSparse(A, B, C);

    cout << "Resultant Matrix C\n";
    display(C);

    return 0;
}
