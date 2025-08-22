#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;


    Node(int value){
        data = value;
        left = right = NULL;
    }


};

// Function to build tree from user input (Level Order)
Node* buildTree(){

int val;
cout<<"Enter root value(-1 for no node): "<<endl;
cin>>val;

if(val == -1)
return NULL;

Node* root = new Node(val);

queue<Node*> q;
/* What does queue<Node*> q; mean?

We are declaring a queue named q.

This queue will store pointers to Node objects. */

q.push(root);

while(!q.empty()){

    Node* current = q.front();
    q.pop();

    int leftVal, rightVal;
    cout<<"Enter the left child of "<<current->data<<" (-1 for no node): ";
    cin>>leftVal;
    if(leftVal != -1){
        current->left = new Node(leftVal);
        q.push(current->left);
    }

   cout << "Enter right child of " << current->data << " (-1 for no node): ";
        cin >> rightVal;
        if(rightVal != -1){
            current->right = new Node(rightVal);
            q.push(current->right);
        }

}

return root;

}

void preorderTraversal(Node* root){
    if(root == NULL)
    return;

    cout<< root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Node* root = buildTree();
    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;
    return 0;
}



