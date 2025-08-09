#include <iostream>
#include <vector>
#include <string>
using namespace std;

int user_logic(const string& S) {
    int n = S.size();
    vector<int> lps(n, 0);

    // Build LPS array
    for (int i = 1, len = 0; i < n; ) {
        if (S[i] == S[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len-1];
        } else {
            lps[i++] = 0;
        }
    }

    // Get the length of the longest prefix which is also suffix
    int len = lps[n-1];
    if (len == 0) return 0; // No echo

    string echo = S.substr(0, len);

    // Count its occurrences in S (sliding window)
    int count = 0;
    for (int i = 0; i+len <= n; i++) {
        if (S.substr(i, len) == echo)
            count++;
    }
    return count;
}

int main() {
    string S;
    cin >> S;
    cout << user_logic(S) << endl;
    return 0;
}
