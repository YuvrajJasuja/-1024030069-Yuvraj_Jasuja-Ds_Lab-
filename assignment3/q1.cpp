#include <iostream>
using namespace std;

int main() {
    int stack[100], top = -1, choice, n, value;
    cout << "Enter stack size: ";
    cin >> n;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (top == n - 1) {
                    cout << "Stack is full\n";
                } else {
                    cout << "Enter value to push: ";
                    cin >> value;
                    stack[++top] = value;
                }
                break;
            case 2:
                if (top == -1) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Popped element: " << stack[top--] << endl;
                }
                break;
            case 3:
                if (top == -1) cout << "Stack is empty\n";
                else cout << "Stack is not empty\n";
                break;
            case 4:
                if (top == n - 1) cout << "Stack is full\n";
                else cout << "Stack is not full\n";
                break;
            case 5:
                if (top == -1) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Stack elements: ";
                    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
                    cout << endl;
                }
                break;
            case 6:
                if (top == -1) cout << "Stack is empty\n";
                else cout << "Top element: " << stack[top] << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
