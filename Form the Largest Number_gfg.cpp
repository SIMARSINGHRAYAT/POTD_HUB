class Solution {
  public:
    static bool compare(int a, int b) {
        // Convert numbers to strings for comparison
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);
        return ab > ba; // Sort in way that forms largest number
    }
    string findLargest(vector<int> &arr) {
        sort(arr.begin(), arr.end(), compare);
        string result;
        for (int num : arr) {
            result += to_string(num);
        }
        // Remove leading zeros (e.g., [0, 0])
        int i = 0;
        while (i < result.size() - 1 && result[i] == '0') i++;
        return result.substr(i);
    }
};
