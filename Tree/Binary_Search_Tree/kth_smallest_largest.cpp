
#include <iostream>
using namespace std;

// Node structure for BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ----------- Find Kth Smallest (inorder = Left -> Root -> Right) -----------
void kthSmallestHelper(TreeNode* root, int& count, int k, int& result) {
    if (!root) return;

    kthSmallestHelper(root->left, count, k, result);  // go left

    count++;  // visit current node
    if (count == k) {
        result = root->val;  // store answer
        return;
    }

    kthSmallestHelper(root->right, count, k, result); // go right
}

// ----------- Find Kth Largest (reverse inorder = Right -> Root -> Left) -----------
void kthLargestHelper(TreeNode* root, int& count, int k, int& result) {
    if (!root) return;

    kthLargestHelper(root->right, count, k, result);  // go right

    count++;
    if (count == k) {
        result = root->val;
        return;
    }

    kthLargestHelper(root->left, count, k, result);   // go left
}

// ----------- Main Function to Get Both Smallest & Largest -----------
pair<int, int> findKth(TreeNode* root, int k) {
    int smallest = -1, largest = -1;
    int count = 0;

    kthSmallestHelper(root, count, k, smallest);

    count = 0; // reset for largest
    kthLargestHelper(root, count, k, largest);

    return {smallest, largest};
}

// ----------- Utility: Inorder Traversal (for printing BST) -----------
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// ----------- Driver Code -----------
int main() {
    // Create a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    cout << "BST in Inorder (sorted): ";
    printInOrder(root);
    cout << endl;

    int k = 3;
    cout << "k = " << k << endl;

    pair<int, int> result = findKth(root, k);

    cout << "Kth smallest = " << result.first << endl;
    cout << "Kth largest = " << result.second << endl;

    return 0;
}
