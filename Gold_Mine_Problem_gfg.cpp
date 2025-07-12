class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initialize first column
        for (int i = 0; i < n; ++i)
            dp[i][0] = mat[i][0];

        // Fill the DP table
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                int right = dp[i][j - 1];
                int right_up = (i > 0) ? dp[i - 1][j - 1] : 0;
                int right_down = (i < n - 1) ? dp[i + 1][j - 1] : 0;

                dp[i][j] = mat[i][j] + max({right, right_up, right_down});
            }
        }

        // Find the maximum value in the last column
        int max_gold = 0;
        for (int i = 0; i < n; ++i)
            max_gold = max(max_gold, dp[i][m - 1]);

        return max_gold;
    }
};
