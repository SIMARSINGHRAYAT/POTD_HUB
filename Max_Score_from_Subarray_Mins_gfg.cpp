class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int maxScore = 0;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; ++i) {
            int score = arr[i] + arr[i + 1];
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};
