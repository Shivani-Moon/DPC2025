#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int low = 1, high = nums.size() - 1, duplicate = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int count = 0;
        for (int num : nums) {
            if (num <= mid) count++;
        }

        if (count > mid) {
            duplicate = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }

    return duplicate;
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}
