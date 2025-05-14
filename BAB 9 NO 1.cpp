#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        auto [node, depth] = q.front(); q.pop();
        if (node->left == nullptr && node->right == nullptr)
            return depth;
        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }
    return 0;
}

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(4);
    root->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(17);

    cout << "Min Depth Binary ini adalah: " << minDepth(root) << endl;

    return 0;
}
