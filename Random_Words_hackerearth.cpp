#include <bits/stdc++.h>
using namespace std;

bool customCompare(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b; // lexicographical comparison
}

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), customCompare);

    for (const string &word : words) {
        cout << word << '\n';
    }

    return 0;
}
