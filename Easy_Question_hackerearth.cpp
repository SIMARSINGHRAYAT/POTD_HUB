#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    vector<string> cycle = {"36", "16", "96", "76", "56"};
    while (T--) {
        string n_str;
        cin >> n_str;
        if (n_str == "1") {
            cout << "6\n";
        } else {
            char last_char = n_str.back();
            int last_digit = last_char - '0';
            int r = last_digit % 5;
            int index = (r + 3) % 5;
            cout << cycle[index] << '\n';
        }
    }
    return 0;
}
