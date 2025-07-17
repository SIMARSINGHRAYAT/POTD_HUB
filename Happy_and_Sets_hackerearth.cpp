#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result = (result * (nums[i] + 1LL)) % MOD;
    }

    result = (result - 1 + MOD) % MOD; // remove empty subset and avoid negative
    cout << result << endl;

    return 0;
}
