#include <iostream>
#include <vector>
#define MOD 1000000007

int ways(int sum) {
    std::vector<int> dp(sum + 1, 0);
    dp[0] = 1; // Base case: one way to make sum 0

    for (int i = 1; i <= sum; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    return dp[sum];
}

int main() {
    int n;
    std::cin >> n;
    int result = ways(n);
    std::cout << result << std::endl;
    return 0;
}
