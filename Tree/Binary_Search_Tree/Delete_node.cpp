#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x){
        val = x;
        right = left = NULL;
    }
};


// Function to find the minimum value node in a given subtree
// (used when deleting a node with two children)
TreeNode* findMin(TreeNode* node) {
    while(node && node->left != NULL){
        node = node->left;
    }
    return node;
}


//Fucntion to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL)
    return root;

    if(key < root->val){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->val){
        root->right = deleteNode(root->right, key);
    }

    else{
        
        // Case 1: Node has no children (leaf)
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;

        }

        // Case 2: Node has only one child
        else if(root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) { // only left child
            TreeNode* temp = root->left;
            delete root;
            return temp;   // connect parent to left child
        }

        // Case 3: Node has two children
        // Step 1: Find the minimum node in the right subtree
        TreeNode* minNode = findMin(root->right);

        // Step 2: Replace current node's value with minNode's value
        root->val = minNode->val;

        // Step 3: Delete the minNode from right subtree
        root->right = deleteNode(root->right, minNode->val);
    }
    return root;

}


// Inorder traversal (prints BST in sorted order)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Create BST manually
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);

    cout << "Before Deletion (Inorder): ";
    inorder(root);
    cout << endl;

    // Delete some nodes
   
    root = deleteNode(root, 15);  // delete node with two children


 cout << "After Deletion (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}







