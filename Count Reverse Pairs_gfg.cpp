#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long mergeAndCount(vector<int>& a, int l, int m, int r) {
        // Count reverse pairs across the split
        long long cnt = 0;
        int j = m + 1;
        for (int i = l; i <= m; ++i) {
            while (j <= r && (long long)a[i] > 2LL * a[j]) j++;
            cnt += (j - (m + 1));
        }

        // Standard merge
        vector<int> tmp;
        tmp.reserve(r - l + 1);
        int i = l; j = m + 1;
        while (i <= m && j <= r) {
            if (a[i] <= a[j]) tmp.push_back(a[i++]);
            else tmp.push_back(a[j++]);
        }
        while (i <= m) tmp.push_back(a[i++]);
        while (j <= r) tmp.push_back(a[j++]);

        // Copy back
        for (int k = 0; k < (int)tmp.size(); ++k) a[l + k] = tmp[k];
        return cnt;
    }

    long long sortAndCount(vector<int>& a, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        long long cnt = 0;
        cnt += sortAndCount(a, l, m);
        cnt += sortAndCount(a, m + 1, r);
        cnt += mergeAndCount(a, l, m, r);
        return cnt;
    }

public:
    int countRevPairs(vector<int>& arr) {
        // Defensive: empty or single element
        if (arr.size() < 2) return 0;
        vector<int> a = arr; // work on a copy to avoid modifying original
        long long ans = sortAndCount(a, 0, (int)a.size() - 1);
        // As per constraints answer fits in int
        return (int)ans;
    }
};
