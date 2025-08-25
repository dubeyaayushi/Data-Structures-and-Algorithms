#include<iostream>
using namespace std;



struct Node{
    int data;
    Node* right;
    Node* left ;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};

Node* insertNode(Node* root, int val)
{
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertNode(root->left, val);
    }

    else if(val > root->data){
        root->right = insertNode(root->right, val);
    }

    return root;

}



//Inorder Traversal
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);

}


int main(){
    Node* root = new Node(10);
    root->left =  new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    cout<<"Before Insertion"<<endl;
    inorder(root);
    cout<<endl;

    insertNode(root, 6);

    cout<<"After insertion"<<endl;
    inorder(root);
    cout<<endl;

    return 0;

}




