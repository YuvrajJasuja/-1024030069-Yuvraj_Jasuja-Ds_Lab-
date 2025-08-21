int** createArray(int rows, int cols) {
    int** arr = new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i] = new int[cols];
    }
    return arr;
}

void printArray(int** arr, int rows, int cols) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
