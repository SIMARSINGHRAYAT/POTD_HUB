#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countMatches(const string& s, const string& p, int k) {
    int count = 0;
    int len_s = s.size(), len_p = p.size();

    for (int i = 0; i <= len_s - len_p; ++i) {
        int mismatch = 0, first = -1, second = -1;

        for (int j = 0; j < len_p; ++j) {
            if (s[i + j] != p[j]) {
                mismatch++;
                if (first == -1) first = j;
                else second = j;
                if (mismatch > 2) break;
            }
        }

        if (mismatch == 0 || mismatch == 1 || (mismatch == 2 && second - first < k))
            count++;
    }

    return count;
}

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> patterns(n);
    for (int i = 0; i < n; ++i)
        cin >> patterns[i];

    for (const string& p : patterns)
        cout << countMatches(s, p, k) << '\n';

    return 0;
}
