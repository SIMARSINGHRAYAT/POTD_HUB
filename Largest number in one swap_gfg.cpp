class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        // Track the index of the max digit from the right
        vector<int> max_idx(n);
        max_idx[n-1] = n-1;
        for(int i = n-2; i >= 0; --i) {
            if(s[i] > s[max_idx[i+1]])
                max_idx[i] = i;
            else
                max_idx[i] = max_idx[i+1];
        }
        // Try to find the first place from left where swapping increases the string
        for(int i = 0; i < n; ++i) {
            if(s[i] < s[max_idx[i]]) {
                swap(s[i], s[max_idx[i]]);
                break; // Only one swap allowed!
            }
        }
        return s;
    }
};
