class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0;
        for (char c : s2) {
            if (i < s1.size() && s1[i] == c) {
                i++;
            }
        }
        return i == s1.size();
    }
};
