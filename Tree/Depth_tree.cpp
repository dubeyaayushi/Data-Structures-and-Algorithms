#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node*  left;

    Node(int val){
        data = val;
        right = left= NULL;
    }
};


int maxDepth(Node* root){
    if(root == NULL){
        return 0;
    }

    queue<Node*>q;
    q.push(root);
    int level=0;

    while(!q.empty()){
        int size = q.size();
        level++;

        for(int i =0; i<size; i++){
            Node* current = q.front();
        q.pop();

         if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }

    }

    return level;

}


int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Maximum Depth of Tree: " << maxDepth(root) << endl;

    return 0;
}


