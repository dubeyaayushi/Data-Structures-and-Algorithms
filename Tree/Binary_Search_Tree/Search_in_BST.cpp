
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    while (root && root->val != val) {
        if (val < root->val) root = root->left;
        else root = root->right;
    }
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    int target = 6;
    TreeNode* result = searchBST(root, target);

    if (result) cout << target << " found!" << endl;
    else cout << target << " not found." << endl;

    return 0;
}
