#include <bits/stdc++.h>
using namespace std;

void process_fault_events(int N, int M, int E,
                          vector<int> &cluster_ids,
                          vector<pair<int,int>> &dependencies,
                          int Q,
                          vector<int> &initial_faults,
                          vector<int> &results) {
    // Convert cluster IDs to 0-based
    for (int i = 0; i < N; i++) {
        cluster_ids[i]--;
    }

    // Count machines per cluster
    vector<int> cluster_size(M, 0);
    for (int i = 0; i < N; i++) {
        cluster_size[cluster_ids[i]]++;
    }

    // Build cluster‐level adjacency (deduped)
    vector<vector<int>> cluster_adj(M);
    cluster_adj.reserve(M);
    for (auto &dep : dependencies) {
        int u = dep.first  - 1;  // 0‐based machine
        int v = dep.second - 1;
        int cu = cluster_ids[u];
        int cv = cluster_ids[v];
        if (cu != cv) {
            cluster_adj[cu].push_back(cv);
        }
    }
    // Remove duplicate edges
    for (int c = 0; c < M; c++) {
        auto &nbrs = cluster_adj[c];
        sort(nbrs.begin(), nbrs.end());
        nbrs.erase(unique(nbrs.begin(), nbrs.end()), nbrs.end());
    }

    // Track which clusters have already failed globally
    vector<char> cluster_failed(M, 0);

    // Process each fault event
    for (int i = 0; i < Q; i++) {
        int f = initial_faults[i] - 1;   // machine index 0‐based
        int start_c = cluster_ids[f];    // its cluster
        int newly_failed = 0;

        // If this cluster is still intact, we BFS from it
        if (!cluster_failed[start_c]) {
            queue<int> bfs;
            cluster_failed[start_c] = 1;
            bfs.push(start_c);
            newly_failed += cluster_size[start_c];

            while (!bfs.empty()) {
                int cu = bfs.front(); 
                bfs.pop();
                for (int cv : cluster_adj[cu]) {
                    if (!cluster_failed[cv]) {
                        cluster_failed[cv] = 1;
                        newly_failed += cluster_size[cv];
                        bfs.push(cv);
                    }
                }
            }
        }

        results[i] = newly_failed;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, E;
    cin >> N >> M >> E;

    vector<int> cluster_ids(N);
    for (int i = 0; i < N; i++) {
        cin >> cluster_ids[i];
    }

    vector<pair<int,int>> dependencies(E);
    for (int i = 0; i < E; i++) {
        cin >> dependencies[i].first
            >> dependencies[i].second;
    }

    int Q;
    cin >> Q;
    vector<int> initial_faults(Q);
    for (int i = 0; i < Q; i++) {
        cin >> initial_faults[i];
    }

    vector<int> results(Q, 0);
    process_fault_events(N, M, E,
                         cluster_ids,
                         dependencies,
                         Q,
                         initial_faults,
                         results);

    for (int x : results) {
        cout << x << "\n";
    }
    return 0;
}
