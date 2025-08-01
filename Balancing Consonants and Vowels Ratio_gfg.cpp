class Solution {
public:
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> freq;
        freq[0] = 1; // Base score for empty prefix
        int score = 0, result = 0;

        for (const string& s : arr) {
            for (char ch : s) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    score += 1;
                } else {
                    score -= 1;
                }
            }
            result += freq[score]; // Count valid subarrays ending at current point
            freq[score]++;
        }

        return result;
    }
};
