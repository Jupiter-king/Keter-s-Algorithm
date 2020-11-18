#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;


bool judge(long long n) {
    if (n < 2)
        return false;
    int sqrt_n = (int) sqrt(n);
    for (int i = 2; i <= sqrt_n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    long long L, K, intN;
    scanf("%lld %lld\n", &L, &K);
    string N;
    getline(cin, N);
    if (N.length() < K or K == 0 or N.length() == 0) {
        cout << 404;
        return 0;
    }
    for (long long i = 0; i < L - K + 1; ++i) {
        long long intN = stoi(N.substr(i, K));
        if (judge(intN)) {
            cout << N.substr(i, K);
            return 0;
        }
    }
    cout << 404;
    return 0;
}