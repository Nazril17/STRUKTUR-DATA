#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBST(TreeNode* root, TreeNode* min = nullptr, TreeNode* max = nullptr) {
    if (root == nullptr) return true;
    if (min && root->val <= min->val) return false;
    if (max && root->val >= max->val) return false;
    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(11);
    root->right->right = new TreeNode(17); 

    if (isBST(root)) {
        cout << "Binary Tree ini adalah BST." << endl;
    } else {
        cout << "Binary Tree ini bukan BST." << endl;
    }

    return 0;
}
