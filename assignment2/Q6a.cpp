#include <iostream>
using namespace std;

void printSparse(int s[][3], int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<3; j++) cout << s[i][j] << " ";
        cout << endl;
    }
}

void transpose(int s[][3], int t[][3]) {
    t[0][0] = s[0][1];   // rows become cols
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];   // number of non-zeros same

    int k = 1;
    for (int col=0; col<s[0][1]; col++) {
        for (int i=1; i<=s[0][2]; i++) {
            if (s[i][1] == col) {
                t[k][0] = s[i][1];   // new row = old col
                t[k][1] = s[i][0];   // new col = old row
                t[k][2] = s[i][2];
                k++;
            }
        }
    }
}

int main() {
    int sparse[4][3] = {
        {3,3,3},
        {0,0,1},
        {1,1,7},
        {2,2,5}
    };

    int trans[4][3];
    transpose(sparse, trans);

    cout << "Original Sparse:\n";
    printSparse(sparse, 4);

    cout << "Transpose Sparse:\n";
    printSparse(trans, 4);
}
