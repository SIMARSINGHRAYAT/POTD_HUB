#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const long long MOD = 1000000007LL;
    string S;
    if(!(cin >> S)) return 0;

    long long A = 0, AB = 0, ABC = 0;

    for (char ch : S) {
        if (ch == 'a') {
            // new A = previous A doubled + start new with this 'a'
            A = ( (A * 2) % MOD + 1 ) % MOD;
        } else if (ch == 'b') {
            // new AB = previous AB doubled + append this 'b' to any A
            AB = ( (AB * 2) % MOD + A ) % MOD;
        } else if (ch == 'c') {
            // new ABC = previous ABC doubled + append this 'c' to any AB
            ABC = ( (ABC * 2) % MOD + AB ) % MOD;
        }
        // other letters are ignored
    }

    cout << ABC % MOD << "\n";
    return 0;
}
