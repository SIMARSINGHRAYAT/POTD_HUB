#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
const int N = 1e6 + 10;

int fact[N];

// Fast exponentiation under modulo
int binExp(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Function to compute (nCk * 2^k) % mod
void solve() {
    int n, k;
    cin >> n >> k;

    int pow2 = binExp(2, k, mod);              // 2^k
    int num = fact[n];                         // n!
    int den = (fact[k] * fact[n - k]) % mod;   // k! * (n-k)!

    int nCk = (num * binExp(den, mod - 2, mod)) % mod;  // nCk using Fermat’s Little Theorem
    int result = (nCk * pow2) % mod;

    cout << result << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Precompute factorials
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; ++i)
        fact[i] = (fact[i - 1] * i) % mod;

    // Read number of test cases
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
