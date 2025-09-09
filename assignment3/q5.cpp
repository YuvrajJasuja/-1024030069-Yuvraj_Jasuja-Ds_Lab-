#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> st;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
                case '^': st.push(pow(op1, op2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;
    cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
