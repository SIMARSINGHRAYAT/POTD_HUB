class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int need = (n + 1) / 2; // ceil(n/2)
        
        int lucky = 0;
        vector<int> costs;
        costs.reserve(n);
        
        for (int x : arr) {
            int r = x % k;
            if (r == 0) {
                lucky++;
            } else {
                costs.push_back(k - r);
            }
        }
        
        if (lucky >= need) return 0;
        
        sort(costs.begin(), costs.end());
        int to_make = need - lucky;
        long long ans = 0;
        for (int i = 0; i < to_make && i < (int)costs.size(); i++) {
            ans += costs[i];
        }
        return (int)ans;
    }
};
