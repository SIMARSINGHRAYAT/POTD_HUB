#include <bits/stdc++.h>
using namespace std;

long long maxProfit(const vector<int>& profits) {
    long long incl = 0; // best profit including current
    long long excl = 0; // best profit excluding current
    for (int x : profits) {
        long long new_incl = excl + x;      // take current -> must have excluded previous
        long long new_excl = max(incl, excl); // skip current -> best of previous states
        incl = new_incl;
        excl = new_excl;
    }
    return max(incl, excl);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    vector<int> profits(N);
    for (int i = 0; i < N; ++i) cin >> profits[i];
    
    cout << maxProfit(profits) << "\n";
    return 0;
}
