class Solution {
  public:
    vector<int> asciirange(string& s) {
        unordered_map<char, pair<int, int>> positions;
        int n = s.size();
        
        // Step 1: Record first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (positions.find(s[i]) == positions.end()) {
                positions[s[i]].first = i;
            }
            positions[s[i]].second = i;
        }

        // Step 2: Compute ASCII sums between first and last occurrence
        vector<int> result;
        for (auto &[ch, range] : positions) {
            int left = range.first, right = range.second;
            if (right - left > 1) {
                int sum = 0;
                for (int i = left + 1; i < right; ++i) {
                    sum += s[i];
                }
                if (sum > 0) result.push_back(sum);
            }
        }

        return result;
    }
};
