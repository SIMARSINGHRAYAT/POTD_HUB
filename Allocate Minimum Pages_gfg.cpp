class Solution {
  public:
    // Helper function to check if we can allocate books with max 'pages' per student
    bool isPossible(vector<int> &arr, int k, int pages) {
        int students = 1;
        int curr_sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > pages) return false; // A book has more pages than mid
            if (curr_sum + arr[i] > pages) {
                students++;
                curr_sum = arr[i];
                if (students > k) return false;
            } else {
                curr_sum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; // Not enough books
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};
