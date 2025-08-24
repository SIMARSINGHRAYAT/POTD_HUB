class Solution {
  public:
    bool possible(vector<int>& arr, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        if ((long long)m * k > arr.size()) return -1;
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(arr, m, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
