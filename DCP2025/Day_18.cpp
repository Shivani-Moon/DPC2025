#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n)
                count += 1; 
            else
                count += 2; 
        }
    }
    return count;
}

int main() {
    long long N;
    cout << "Enter a number: ";
    cin >> N;

    cout << "Number of divisors: " << countDivisors(N) << endl;

    return 0;
}
