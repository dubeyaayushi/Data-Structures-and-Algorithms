#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* right;
    Node* left;

    Node (int val){
        data = val;
        right = left = NULL;
    }

};
    //function to compute the diameter
     
    int findMax(Node* node, int &maxi){
        if(node == NULL)
        return 0;

        int lh = findMax(node->left, maxi);
        int rh = findMax(node->right, maxi);

        maxi = max(maxi, lh +rh);

        return 1+ max(lh,rh);
    }



int diameterOfBinaryTree(Node* root) {
    int maxi = 0;
    findMax(root, maxi);
    return maxi;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of the binary tree is: " 
         << diameterOfBinaryTree(root) << endl;

    return 0;
}









