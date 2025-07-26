#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// Solves one test case
int maxReachableRow(int n, const vector<pair<int, int>>& obstacles) {
    unordered_map<int, unordered_set<int>> obs;
    for (auto& [x, y] : obstacles) {
        obs[x].insert(y);
    }

    // Get sorted list of obstacle rows
    vector<int> rows;
    for (auto& [x, _] : obstacles) {
        rows.push_back(x);
    }
    sort(rows.begin(), rows.end());
    rows.erase(unique(rows.begin(), rows.end()), rows.end());

    unordered_set<int> reachable = {1, 2, 3}; // Can start from any column in row 1
    int lastRow = 1;

    for (int row : rows) {
        if (reachable.empty())
            break;

        unordered_set<int> nextReach;
        for (int col : reachable) {
            for (int d = -1; d <= 1; ++d) {
                int nc = col + d;
                if (nc >= 1 && nc <= 3 && !obs[row].count(nc)) {
                    nextReach.insert(nc);
                }
            }
        }

        if (nextReach.empty())
            return row - 1;

        reachable = move(nextReach);
        lastRow = row;
    }

    return reachable.empty() ? lastRow : n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, q;
        cin >> n >> q;

        vector<pair<int, int>> obstacles;
        for (int i = 0; i < q; ++i) {
            int x, y;
            cin >> x >> y;
            obstacles.emplace_back(x, y);
        }

        cout << maxReachableRow(n, obstacles) << '\n';
    }

    return 0;
}
