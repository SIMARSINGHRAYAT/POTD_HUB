#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Traverse from right to left using a stack
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && freq[st.top()] <= freq[arr[i]]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }

        return result;
    }
};
