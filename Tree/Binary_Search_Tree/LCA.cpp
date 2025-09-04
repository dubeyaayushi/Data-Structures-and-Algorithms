#include<iostream>
using namespace std;


struct Node{
    int data; 
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }


};


// Function to insert a new node in BST
Node* insert(Node* root, int val) {
    if (root == NULL) 
        return new Node(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}


// Inorder traversal for checking
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//FUnction to find LCA
Node* LCA(Node* root, int n1, int n2){
    if(root == NULL)
    return NULL;

    if(n1<root->data && n2<root->data){
        return LCA(root->left, n1, n2);
    }

    if(n1>root->data && n2 >root->data){
        return LCA(root->right, n1 , n2);
    }

    return root;
}


int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int n1 = 5, n2 = 15;
    Node* lca = LCA(root, n1, n2);
    if (lca != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "Keys are not present in the tree" << endl;

    return 0;
}











