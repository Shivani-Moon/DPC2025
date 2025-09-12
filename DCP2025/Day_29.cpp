#include <iostream>
#include <vector>
using namespace std;

long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter n (0 ≤ n ≤ 1000): ";
    cin >> n;

    cout << "The " << n << "-th Fibonacci number is: " << fibonacci(n) << endl;

    return 0;
}
