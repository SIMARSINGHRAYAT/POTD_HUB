class Solution {
  public:
    int kadaneMax(const vector<int>& arr) {
        int maxEndingHere = arr[0], maxSoFar = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }

    int kadaneMin(const vector<int>& arr) {
        int minEndingHere = arr[0], minSoFar = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            minEndingHere = min(arr[i], minEndingHere + arr[i]);
            minSoFar = min(minSoFar, minEndingHere);
        }
        return minSoFar;
    }

    int maxCircularSum(vector<int> &arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int maxKadane = kadaneMax(arr);
        int minKadane = kadaneMin(arr);
        
        // If all numbers are negative, maxKadane already gives the correct result
        if (maxKadane < 0)
            return maxKadane;
        
        // Otherwise, take the max of non-circular and circular case
        return max(maxKadane, totalSum - minKadane);
    }
};
