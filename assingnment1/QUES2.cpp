#include<iostream>
using namespace std;

void removeDuplicates(int arr[], int &size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                // Shift elements to the left
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;   // Reduce size after removing duplicate
                j--;      // Re-check the new element at position j
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter element at position " << i << ": ";
        cin >> arr[i];
    }
    
    removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
