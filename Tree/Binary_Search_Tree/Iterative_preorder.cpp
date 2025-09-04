#include<iostream>
#include<stack>
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


void iterative(Node* root){
    if(root == NULL)
    return ;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* curr = st.top();
        st.pop();

        cout<<curr->data<<" ";

        if(curr->right) 
        st.push(curr->right);
        if(curr->left)
        st.push(curr->left);
    }

}



int main() {
    /* 
        Constructing this tree:
                10
               /  \
              20   30
             / \   / \
            40 50 60 70
    */
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << "Iterative Preorder Traversal: ";
    iterative(root);
    cout << endl;

    return 0;
}













