class Solution {
public:
    bool canAchieve(vector<int>& arr, int target, int k) {
        int n = arr.size();
        long long ops = 0;
        
        if (n % 2 == 1) {
            for (int i = n/2; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        } else {
            long long medianSum = arr[n/2-1] + arr[n/2];
            if (2LL * target > medianSum) {
                ops += 2LL * target - medianSum;
                if (ops > k) return false;
            }
            for (int i = n/2+1; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        }
        return true;
    }
    
    int maximizeMedian(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int l = (n % 2 == 1) ? arr[n/2] : (arr[n/2-1] + arr[n/2]) / 2;
        int r = l + k;
        int ans = l;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canAchieve(arr, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
