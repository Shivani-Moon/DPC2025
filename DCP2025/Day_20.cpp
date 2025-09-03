#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &st, int element) {
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(topElement);
}

void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, topElement);
}

void printStack(stack<int> st) {
    vector<int> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin(), temp.end()); 
    for (int x : temp) cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements in stack: ";
    cin >> n;

    stack<int> st;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    printStack(st);

    return 0;
}
