#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int matrix[4][4] = {
        {1, 2, 0, 0},
        {3, 4, 5, 0},
        {0, 6, 7, 8},
        {0, 0, 9, 10}
    };

    int size = 3*n - 2;
    int tri[size];
    int k = 0;

    for(int i=0; i<n; i++) {
        tri[k++] = matrix[i][i]; 

        if(i-1 >= 0) tri[k++] = matrix[i][i-1];
                      
        if(i+1 < n) tri[k++] = matrix[i][i+1]; 
    }

    cout << "Stored tri-diagonal elements: ";
    for(int i=0; i<size; i++) cout << tri[i] << " ";
    cout << endl;
}
