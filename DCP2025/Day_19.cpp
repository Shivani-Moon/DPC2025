#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(const string &expr) {
    stack<int> st;
    int n = expr.size();

    for (int i = 0; i < n; ) {
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(expr[i]) || (expr[i] == '-' && i + 1 < n && isdigit(expr[i + 1]))) {
            int sign = 1;
            if (expr[i] == '-') {
                sign = -1;
                i++;
            }
            int num = 0;
            while (i < n && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            st.push(sign * num);
        } 
        else {
            char op = expr[i];
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (op == '+') st.push(a + b);
            else if (op == '-') st.push(a - b);
            else if (op == '*') st.push(a * b);
            else if (op == '/') st.push(a / b);

            i++;
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    getline(cin, expr);

    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
