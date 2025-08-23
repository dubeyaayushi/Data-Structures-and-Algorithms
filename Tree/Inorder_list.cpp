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


Node* buildTree(){

    int val; 
    cout<<"Enter the root value(-1 for no node)"<<endl;
    cin>>val;
    if( val == -1)
    {
        return NULL;
    }

    Node* root = new Node(val);

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){

        Node* current = q.front();
        q.pop();

        int leftval, rightval;

        cout<<"Enter rthe value for left child of"<<current->data<<"(-1 for no node):";
        cin>>leftval;

        if(leftval!= -1){
            current->left = new Node(leftval);
            q.push(current->left);
        }

        cout<<"Enter the value for right child of "<<current->data<<"(-1 for no node):";
        cin>>rightval;

        if(rightval!= -1){
            current->right = new Node(rightval);
            q.push(current->right);
        }
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
     cout << root->data << " ";  
    inorderTraversal(root->right);
}

int main() {
    Node* root = buildTree();
       inorderTraversal(root);
    return 0;
}











