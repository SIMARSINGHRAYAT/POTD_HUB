#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build binary tree from level order input
TreeNode* buildTree(vector<string> &nodes) {
    if (nodes.empty() || nodes[0] == "N") return NULL;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1, n = nodes.size();
    while (!q.empty() && i < n) {
        TreeNode* curr = q.front(); q.pop();
        if (i < n && nodes[i] != "N") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if (i < n && nodes[i] != "N") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Traverse right path and sum up
int rightPathSum(TreeNode *root) {
    int sum = 0;
    TreeNode *curr = root;
    while (curr) {
        sum += curr->val;
        if (!curr->right) break;
        curr = curr->right;
    }
    return sum;
}

// Check perfect square
bool isPerfectSquare(int x) {
    int s = sqrt(x);
    return s * s == x;
}

// Main function
int main() {
    int M;
    cin >> M;
    vector<string> nodes(M);
    for (int i = 0; i < M; ++i) cin >> nodes[i];
    TreeNode* root = buildTree(nodes);
    int sum = rightPathSum(root);
    cout << (isPerfectSquare(sum) ? "YES" : "NO") << endl;
    return 0;
}
