class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> rowSum(n, 0), colSum(n, 0);
        int total = 0, maxSum = 0;

        // Step 1: Compute row sums, column sums, and total matrix sum
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
                total += mat[i][j];
            }

        // Step 2: Find the maximum among all row and column sums
        for (int i = 0; i < n; ++i)
            maxSum = max({maxSum, rowSum[i], colSum[i]});

        // Step 3: Calculate required operations
        return n * maxSum - total;
    }
};
