class Solution {
  public:
    int cuts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1e9); // Initialize with a large number
        dp[0] = 0;

        // Precompute valid binary strings representing powers of 5
        unordered_set<string> valid;
        long long num = 1;
        while (true) {
            string bin = "";
            long long temp = num;
            while (temp) {
                bin = char(temp % 2 + '0') + bin;
                temp /= 2;
            }
            if (bin.size() > 30) break;
            valid.insert(bin);
            num *= 5;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);
                if (sub[0] != '0' && valid.count(sub)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] == 1e9 ? -1 : dp[n];
    }
};
