#include <iostream>
using namespace std;

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    char stack[100];
    int top = -1;
    bool balanced = true;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                balanced = false;
                break;
            }
            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                balanced = false;
                break;
            }
        }
    }

    if (top != -1) balanced = false;

    if (balanced) cout << "Expression is balanced\n";
    else cout << "Expression is not balanced\n";

    return 0;
}
