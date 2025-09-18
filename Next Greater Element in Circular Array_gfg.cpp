class Solution {
public:
    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        // Traverse twice for circular effect
        for(int i = 2*n-1; i >= 0; i--) {
            int curr = arr[i % n];
            // Pop elements less than or equal to current
            while(!st.empty() && st.top() <= curr)
                st.pop();
            if(i < n) {
                if(!st.empty())
                    res[i] = st.top();
                // else res[i] remains -1
            }
            // Push current to stack
            st.push(curr);
        }
        return res;
    }
};
