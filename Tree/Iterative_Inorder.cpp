#include<iostream>
#include<stack>
#include<vector>
using namespace std; 

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data = val;
        right = left = NULL;
    }
};


void inorder(Node* root, vector<int> &arr){
    if(root == NULL)
    return ;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);

   
}

vector<int> inOrder(Node* root){
    vector<int> arr;
    inorder(root, arr);

    return arr;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
       
        cout << val << " ";
    }
    cout << endl;

    return 0;
}








