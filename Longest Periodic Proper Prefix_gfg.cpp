class Solution {
public:
    int getLongestPrefix(string s) {
        int n = s.size(), l = 0, r = 0, ans = -1;
        vector<int> z(n);
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            if (z[i] == n - i) ans = i;
        }
        return ans;
    }
};
