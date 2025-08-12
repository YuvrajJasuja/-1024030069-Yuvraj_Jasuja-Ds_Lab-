
#include <iostream>
using namespace std;



void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
