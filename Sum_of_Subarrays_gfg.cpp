class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += arr[i] * (i + 1) * (n - i);
        }

        return totalSum;
    }
};
