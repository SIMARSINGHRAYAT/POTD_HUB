#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int countUniqueVariables(int N, vector<string>& statements) {
        unordered_set<string> variables;

        for (const string& stmt : statements) {
            size_t pos = stmt.find('=');
            if (pos != string::npos) {
                string var = stmt.substr(0, pos);
                
                // Trim spaces
                size_t start = var.find_first_not_of(" \t");
                size_t end = var.find_last_not_of(" \t");
                if (start != string::npos && end != string::npos)
                    var = var.substr(start, end - start + 1);

                variables.insert(var);
            }
        }

        return variables.size();
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // consume leftover newline
    vector<string> statements(N);

    for (int i = 0; i < N; ++i) {
        getline(cin, statements[i]);
    }

    Solution sol;
    cout << sol.countUniqueVariables(N, statements) << endl;

    return 0;
}
