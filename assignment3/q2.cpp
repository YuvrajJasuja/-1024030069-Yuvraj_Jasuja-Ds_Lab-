#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();
    char stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) stack[++top] = str[i];

    cout << "Reversed string: ";
    while (top != -1) cout << stack[top--];
    cout << endl;

    return 0;
}
