#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders(n); 
    int count = 0;           

    int maxFromRight = arr[n - 1];
    leaders[count++] = maxFromRight; 

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            leaders[count++] = arr[i];
        }
    }
    reverse(leaders.begin(), leaders.begin() + count);
    leaders.resize(count);
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findLeaders(arr);

    cout << "Leaders: ";
    for (int i = 0; i < leaders.size(); i++) {
        cout << leaders[i] << " ";
    }
    cout << endl;

    return 0;
}
