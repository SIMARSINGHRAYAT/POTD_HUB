class Solution {
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 0, high = arr[n-1] - arr[0], ans = 0;
        
        auto isPossible = [&](int minDiff) {
            int count = 1, last = arr[0];
            for (int i = 1; i < n; ++i) {
                if (arr[i] - last >= minDiff) {
                    count++;
                    last = arr[i];
                }
                if (count == k) return true;
            }
            return false;
        };
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
