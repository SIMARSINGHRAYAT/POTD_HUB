class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixCount;
        int count = 0, sum = 0;

        prefixCount[0] = 1;  // to handle subarrays starting at index 0

        for (int num : arr) {
            sum += num;
            
            // Check if there's a prefix with sum = (sum - k)
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }
            
            // Update the count for current prefix sum
            prefixCount[sum]++;
        }

        return count;
    }
};
