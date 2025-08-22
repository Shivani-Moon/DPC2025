#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    string words[10000]; 
    int wordCount = 0;

    string temp = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            temp += s[i];  
        } else {
            if (!temp.empty()) {
                words[wordCount++] = temp; 
                temp = "";
            }
        }
    }
    if (!temp.empty()) {
        words[wordCount++] = temp; 
    }

    string result = "";
    for (int i = wordCount - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) result += " ";
    }
    return result;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    cout << "Output: " << reverseWords(s) << endl;
    return 0;
}
