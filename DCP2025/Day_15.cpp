#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastIndex;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        if (lastIndex.find(s[right]) != lastIndex.end()) {
            left = max(left, lastIndex[s[right]] + 1);
        }
        lastIndex[s[right]] = right; 
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;

    return 0;
}
