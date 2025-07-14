#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        long long xorsum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            xorsum ^= a[i];
        }

        // If already a losing position, no winning move
        if(xorsum == 0){
            cout << 0 << "\n";
            continue;
        }

        // Count heaps i for which reducing a[i] to (a[i] xor xorsum)
        // is strictly smaller than a[i].  Each such heap yields exactly
        // one move that makes the resulting XOR = 0.
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            long long target = a[i] ^ xorsum;
            if(target < a[i]) 
                cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}
