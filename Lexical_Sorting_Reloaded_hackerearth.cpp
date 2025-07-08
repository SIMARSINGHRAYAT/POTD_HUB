#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator for sorting
bool customCompare(const string &a, const string &b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; ++i) {
        if (a[i] == b[i]) continue;

        // Space has highest priority
        if (a[i] == ' ') return true;
        if (b[i] == ' ') return false;

        // If characters differ
        if (tolower(a[i]) != tolower(b[i]))
            return tolower(a[i]) < tolower(b[i]);

        // Same letter, but one is lowercase
        return islower(a[i]);
    }
    return a.size() < b.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cin.ignore(); // To consume the newline after N

        vector<string> strings(N);
        for (int i = 0; i < N; ++i) {
            getline(cin, strings[i]);
        }

        sort(strings.begin(), strings.end(), customCompare);

        for (const string &s : strings) {
            cout << s << '\n';
        }
    }

    return 0;
}
