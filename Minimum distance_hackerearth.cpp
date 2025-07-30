#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];

// Multi-source BFS to find max of min-distances
int compute_max_distance(int n, const vector<int>& sources) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    for (int src : sources) {
        if (dist[src] == -1) {
            dist[src] = 0;
            q.push(src);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; ++i) {
        maxDist = max(maxDist, dist[i]);
    }
    return maxDist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Build the tree
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Process each query
    while (q--) {
        int k;
        cin >> k;
        vector<int> sources(k);
        for (int i = 0; i < k; ++i) {
            cin >> sources[i];
        }
        cout << compute_max_distance(n, sources) << "\n";
    }

    return 0;
}
