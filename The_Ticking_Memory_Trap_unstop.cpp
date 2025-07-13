#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Node {
    long long val;
    Node *left, *right;
    Node(long long v = 0) : val(v), left(nullptr), right(nullptr) {}
};

vector<Node*> versionRoots;

Node* build(vector<int>& arr, int l, int r) {
    Node* node = new Node();
    if (l == r) {
        node->val = arr[l];
        return node;
    }
    int mid = (l + r) / 2;
    node->left = build(arr, l, mid);
    node->right = build(arr, mid + 1, r);
    node->val = node->left->val + node->right->val;
    return node;
}

Node* update(Node* prev, int l, int r, int idx, int val) {
    Node* node = new Node();
    if (l == r) {
        node->val = val;
        return node;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        node->left = update(prev->left, l, mid, idx, val);
        node->right = prev->right;
    } else {
        node->left = prev->left;
        node->right = update(prev->right, mid + 1, r, idx, val);
    }
    node->val = node->left->val + node->right->val;
    return node;
}

long long query(Node* node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return node->val;
    int mid = (l + r) / 2;
    return query(node->left, l, mid, ql, qr) + query(node->right, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    // Build initial version
    versionRoots.push_back(build(arr, 0, n - 1));

    for (int i = 0; i < q; ++i) {
        int type; cin >> type;
        if (type == 1) {
            int v, idx, x;
            cin >> v >> idx >> x;
            --idx;
            Node* newRoot = update(versionRoots[v - 1], 0, n - 1, idx, x);
            versionRoots.push_back(newRoot);
        } else {
            int v, l, r;
            cin >> v >> l >> r;
            --l; --r;
            cout << query(versionRoots[v - 1], 0, n - 1, l, r) << '\n';
        }
    }

    return 0;
}
