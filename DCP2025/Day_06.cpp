#include <bits/stdc++.h>
using namespace std;

struct Subarray {
    int start;
    int end;
};

int main() {
    int arr[] = {1, 2, -3, 3, -1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Subarray results[1000];
    int resultCount = 0;

    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += arr[end];
            if (sum == 0) {
                results[resultCount].start = start;
                results[resultCount].end = end;
                resultCount++;
            }
        }
    }

    if (resultCount == 0) {
        cout << "[]" << endl;
    } else {
        cout << "[";
        for (int i = 0; i < resultCount; i++) {
            cout << "(" << results[i].start << ", " << results[i].end << ")";
            if (i != resultCount - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
