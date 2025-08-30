#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long findLCM(long long a, long long b) {
    return (a / gcd(a, b)) * b; 
}

int main() {
    long long N, M;
    cin >> N >> M;

    cout << findLCM(N, M) << endl;

    return 0;
}
