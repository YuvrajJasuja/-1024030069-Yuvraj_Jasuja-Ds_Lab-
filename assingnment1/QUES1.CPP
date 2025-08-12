#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int n = 0; // Current size of array

// CREATE array
void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Size exceeds max limit.\n";
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}

// DISPLAY array
void displayArray() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// INSERT element
void insertElement() {
    if (n >= MAX) {
        cout << "Array is full.\n";
        return;
    }
    int pos, value;
    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    cout << "Element inserted successfully.\n";
}

// DELETE element
void deleteElement() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int pos;
    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully.\n";
}

// LINEAR SEARCH
void linearSearch() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << ".\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

// MAIN function with menu
int main() {
    int choice;
    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
