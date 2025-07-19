class Solution {
public:
    int vowelCount(string& s) {
        int freq[26] = {}, cnt = 0, mul = 1;
        for (char c : s) if (strchr("aeiou", c)) freq[c - 'a']++;
        for (int v : {0, 4, 8, 14, 20}) if (freq[v]) mul *= freq[v], cnt++;
        return cnt ? mul * tgamma(cnt + 1) : 0;
    }
};
