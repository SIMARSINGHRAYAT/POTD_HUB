#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canFormPalindrome(const string& s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    int odd = 0;
    for (int count : freq) if (count % 2) odd++;
    return odd <= 1;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        string rotation = s.substr(i) + s.substr(0, i);
        if (canFormPalindrome(rotation)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
