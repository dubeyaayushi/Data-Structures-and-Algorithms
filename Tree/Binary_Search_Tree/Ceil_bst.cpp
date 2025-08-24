#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};


int findCeil(Node* root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            return root->data;
        }
        if(root-> data < key){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    int key = 7;
    int ans = findCeil(root, key);
    if (ans == -1) cout << "No ceil exists\n";
    else cout << "Ceil of " << key << " is " << ans << endl;

    return 0;
}










