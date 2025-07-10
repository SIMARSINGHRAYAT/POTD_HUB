class Solution {
  public:
    int countConsec(int n) {
        vector<int> dp(n + 1);
        dp[1] = 2; // "0", "1"
        dp[2] = 3; // "00", "01", "10"

        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int total = 1 << n; // 2^n
        return total - dp[n];
    }
};
