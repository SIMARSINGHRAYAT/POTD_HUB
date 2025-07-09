#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;

// Prime factorization of numbers from 1 to 10
map<int, vector<pair<int, int>>> prime_factors = {
    {1, {}},
    {2, {{2, 1}}},
    {3, {{3, 1}}},
    {4, {{2, 2}}},
    {5, {{5, 1}}},
    {6, {{2, 1}, {3, 1}}},
    {7, {{7, 1}}},
    {8, {{2, 3}}},
    {9, {{3, 2}}},
    {10, {{2, 1}, {5, 1}}}
};

int N, M;
int A[MAXN];
map<int, vector<int>> prefix_exp; // prime -> prefix sum of exponents

int mod_mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Collect all primes used in 1 to 10
    set<int> all_primes;
    for (auto& [num, factors] : prime_factors) {
        for (auto& [p, _] : factors) {
            all_primes.insert(p);
        }
    }

    // Initialize prefix sums for each prime
    for (int p : all_primes) {
        prefix_exp[p] = vector<int>(N + 1, 0);
    }

    // Build prefix sums of prime exponents
    for (int i = 1; i <= N; ++i) {
        for (int p : all_primes) {
            prefix_exp[p][i] = prefix_exp[p][i - 1]; // carry forward
        }
        for (auto [p, e] : prime_factors[A[i]]) {
            prefix_exp[p][i] += e;
        }
    }

    // Answer queries
    while (M--) {
        int l, r;
        cin >> l >> r;
        int result = 1;
        for (int p : all_primes) {
            int exp = prefix_exp[p][r] - prefix_exp[p][l - 1];
            result = mod_mul(result, exp + 1);
        }
        cout << result << '\n';
    }

    return 0;
}
