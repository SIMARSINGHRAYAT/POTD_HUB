class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        int count1 = 0, count2 = 0;

        // First pass: find potential candidates
        for (int num : arr) {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Second pass: verify actual counts
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }

        vector<int> result;
        int threshold = n / 3;
        if (count1 > threshold)
            result.push_back(candidate1);
        if (candidate2 != candidate1 && count2 > threshold)
            result.push_back(candidate2);

        sort(result.begin(), result.end());
        return result;
    }
};
