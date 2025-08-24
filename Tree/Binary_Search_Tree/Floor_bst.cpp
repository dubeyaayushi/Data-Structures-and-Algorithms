#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findFloor(TreeNode* root, int key) {
    int floor = -1;
    while (root) {
        if (root->val == key) {
            return root->val;  // exact match
        }
        if (root->val > key) {
            root = root->left;  // move left (need smaller)
        } else {
            floor = root->val;  // possible floor
            root = root->right; // try larger but still <= key
        }
    }
    return floor;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    int key = 9;
    int ans = findFloor(root, key);
    if (ans == -1) cout << "No floor exists\n";
    else cout << "Floor of " << key << " is " << ans << endl;

    return 0;
}
