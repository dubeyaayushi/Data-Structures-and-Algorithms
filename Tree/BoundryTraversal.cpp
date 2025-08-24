#include<iostream>
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

bool isLeaf(Node* root){
    return (root->left == nullptr && root->right == nullptr);
}

//Add left boundary
void addleftBoundary(Node* root, vector<int>& res){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr))
        res.push_back(curr->data);
       if(curr->left)
       curr = curr->left;
       else 
       curr = curr->right;
    }
}


//Add right boundary 
void addRightBoundary(Node* root, vector<int>& result)
{
    Node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) 
        curr = curr-> right;
        else curr = curr->left;
    }
       for (int i = temp.size() - 1; i >= 0; i--) {
        result.push_back(temp[i]);
    }
}


//Add all leaf nodes
void addLeaves(Node* root, vector<int>& result){
     if (isLeaf(root)) {
        result.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, result);
    if (root->right) addLeaves(root->right, result);
}

// Boundary Traversal
vector<int> boundaryTraversal(Node* root) {
    vector<int> result;
    if (!root) return result;

    // Add root (only if not leaf)
    if (!isLeaf(root)) result.push_back(root->data);

    addleftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root, result);

    return result;
}

// Print result
void print(vector<int>& result) {
    for (int val : result) cout << val << " ";
    cout << endl;
}


int main() {
    // Create a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Get and print boundary traversal
    vector<int> result = boundaryTraversal(root);
    cout << "Boundary Traversal: ";
    print(result);

    return 0;
}






