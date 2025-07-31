#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

string findLexSmallestPath(const vector<string>& grid, int n) {
    using State = pair<string, pair<int, int>>; // {path, {i, j}}
    priority_queue<State, vector<State>, greater<State>> pq;
    set<pair<int, int>> visited;

    pq.push({string(1, grid[0][0]), {0, 0}});

    while (!pq.empty()) {
        auto [path, pos] = pq.top(); pq.pop();
        int i = pos.first, j = pos.second;

        if (i == n - 1 && j == n - 1) return path;

        if (visited.count(pos)) continue;
        visited.insert(pos);

        if (i + 1 < n)
            pq.push({path + grid[i + 1][j], {i + 1, j}});
        if (j + 1 < n)
            pq.push({path + grid[i][j + 1], {i, j + 1}});
    }

    return ""; // Should never reach here
}


int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // Call user logic function and print the output
    string result = findLexSmallestPath(grid, n);
    cout << result << endl;

    return 0;
}
