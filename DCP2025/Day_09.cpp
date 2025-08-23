#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0]; 

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j); 
        if (prefix.empty()) return "";
    }

    return prefix;
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs2) << endl;

    return 0;
}
