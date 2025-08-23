#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* left ;
    Node* right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

void postOrderTraversal(Node* root){
    if(root == NULL)
    return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
     cout << root->data << " ";  

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"PostOrder Traversal: ";
    postOrderTraversal(root);
    cout<<endl;

    return 0;
}



