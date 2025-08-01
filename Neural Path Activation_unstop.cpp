#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class SegmentTree {
public:
    int size;
    vector<int> tree, lazy;

    SegmentTree(int n) : size(n), tree(4 * n), lazy(4 * n) {}

    void push(int node, int l, int r) {
        if (lazy[node]) {
            tree[node] = (r - l + 1) - tree[node]; // Flip active/inactive
            if (l != r) {
                lazy[2 * node] ^= 1;
                lazy[2 * node + 1] ^= 1;
            }
            lazy[node] = 0;
        }
    }

    void toggle(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            lazy[node] ^= 1;
            push(node, l, r);
            return;
        }
        int m = (l + r) / 2;
        toggle(2 * node, l, m, ql, qr);
        toggle(2 * node + 1, m + 1, r, ql, qr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
    }
};

vector<vector<int>> adj;
vector<int> parent, depth, heavy, head, pos;
int cur_pos = 0;

int dfs(int u) {
    int size = 1, max_subtree = 0;
    for (int v : adj[u]) {
        if (v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            int subtree = dfs(v);
            size += subtree;
            if (subtree > max_subtree) {
                max_subtree = subtree;
                heavy[u] = v;
            }
        }
    }
    return size;
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = cur_pos++;
    if (heavy[u] != -1) decompose(heavy[u], h);
    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u]) decompose(v, v);
    }
}

void path_toggle(int u, int v, SegmentTree &seg) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        seg.toggle(1, 0, seg.size - 1, pos[head[u]], pos[u]);
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (u != v) seg.toggle(1, 0, seg.size - 1, pos[u] + 1, pos[v]); // edge logic
}

int path_query(int u, int v, SegmentTree &seg) {
    int res = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        res += seg.query(1, 0, seg.size - 1, pos[head[u]], pos[u]);
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    if (u != v) res += seg.query(1, 0, seg.size - 1, pos[u] + 1, pos[v]);
    return res;
}

void process_queries(int n, vector<pair<int, int>>& edges, vector<tuple<int, int, int>>& queries) {
    adj.resize(n + 1);
    for (auto &[u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent.resize(n + 1);
    depth.resize(n + 1);
    heavy.assign(n + 1, -1);
    head.resize(n + 1);
    pos.resize(n + 1);

    parent[1] = 0;
    depth[1] = 0;
    dfs(1);
    decompose(1, 1);

    SegmentTree seg(n);
    for (auto &[t, u, v] : queries) {
        if (t == 1) {
            path_toggle(u, v, seg);
        } else {
            cout << path_query(u, v, seg) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int q;
    cin >> q;
    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        queries[i] = make_tuple(t, u, v);
    }

    process_queries(n, edges, queries);
    return 0;
}
