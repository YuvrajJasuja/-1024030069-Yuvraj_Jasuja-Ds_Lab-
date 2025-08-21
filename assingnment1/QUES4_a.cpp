
#include <iostream>
using namespace std;



void reverseArray(int arr[], int size) 
    {
        for(int i=size-1;i>=0;i--)
        cout<<arr[i]<<" ";
    }


int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) 
    cin >> arr[i];
    reverseArray(arr, size);
    return 0;
}
