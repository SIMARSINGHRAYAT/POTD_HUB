#include <bits/stdc++.h>
using namespace std;

struct State {
    int r, c, dir; // dir: 0=up,1=down,2=left,3=right, -1=start
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));

    int startR, startC;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 3) {
                startR = i;
                startC = j;
            }
        }
    }

    // Directions: up, down, left, right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    const int INF = 1e9;
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(4, INF)));

    deque<State> dq;

    // Initial moves: can go in any direction without counting a turn
    for (int d = 0; d < 4; d++) {
        int nr = startR + dr[d];
        int nc = startC + dc[d];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] != 1) {
            dist[nr][nc][d] = 0;
            dq.push_back({nr, nc, d});
        }
    }

    while (!dq.empty()) {
        auto [r, c, dir] = dq.front();
        dq.pop_front();

        // Check if it's a hospital
        if (grid[r][c] == 2) {
            cout << dist[r][c][dir] << "\n";
            return 0;
        }

        for (int ndir = 0; ndir < 4; ndir++) {
            int nr = r + dr[ndir];
            int nc = c + dc[ndir];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || grid[nr][nc] == 1)
                continue;

            int extra = (ndir == dir ? 0 : 1);
            int newCost = dist[r][c][dir] + extra;

            if (newCost < dist[nr][nc][ndir]) {
                dist[nr][nc][ndir] = newCost;
                if (extra == 0) {
                    dq.push_front({nr, nc, ndir}); // No turn → front
                } else {
                    dq.push_back({nr, nc, ndir});  // Turn → back
                }
            }
        }
    }

    // If we reach here → no hospital reachable
    cout << -1 << "\n";
    return 0;
}
