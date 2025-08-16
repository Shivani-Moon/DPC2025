#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& arr, int n) {
    long long totalSum = (1LL * n * (n + 1)) / 2;

    long long arrSum = 0;
    for (int num : arr) {
        arrSum += num;
    }
    return totalSum - arrSum;
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<int> arr(n - 1);
    cout << "Enter " << n - 1 << " elements: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number: " << findMissingNumber(arr, n) << endl;
    return 0;
}
