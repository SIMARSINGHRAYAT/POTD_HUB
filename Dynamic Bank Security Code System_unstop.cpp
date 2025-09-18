#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> security_strings(N);
    for (int i = 0; i < N; ++i) {
        cin >> security_strings[i];
    }
    int max_code = -1, max_idx = -1;
    for (int i = 0; i < N; ++i) {
        int total = 0;
        string &s = security_strings[i];
        for (int j = 0; j < s.size(); ++j) {
            int d = s[j] - '0', idx = j + 1;
            if (d % 2 == 0) total += d * idx;
            else total -= d * idx;
        }
        int code = abs(total);
        if (code > max_code) {
            max_code = code;
            max_idx = i;
        }
    }
    cout << (max_idx + 1) << " " << max_code << endl;
    return 0;
}
