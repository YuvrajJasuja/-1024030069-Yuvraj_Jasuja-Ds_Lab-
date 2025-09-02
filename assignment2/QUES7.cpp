#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) if (arr[i] == arr[j]) break;
        if (i == j) count++;
    }

    cout << count;
    return 0;
}
