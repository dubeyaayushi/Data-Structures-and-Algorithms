#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(TreeNode* root, int minVal, int maxVal) {
    if (root == nullptr) return true;

    if (root->val <= minVal || root->val >= maxVal) return false;

    return isBSTUtil(root->left, minVal, root->val) &&
           isBSTUtil(root->right, root->val, maxVal);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6); // ❌ breaks BST rule
    root->right->right = new TreeNode(20);

    if (isBST(root))
        cout << "This tree IS a BST ✅" << endl;
    else
        cout << "This tree is NOT a BST ❌" << endl;

    return 0;
}


/*          10
        /  \
       5    15
           /  \
          6    20
Step 1: main()
Creates nodes.

Calls isBST(root) with root = 10.

isBST() → calls isBSTUtil(root, INT_MIN, INT_MAX)

Step 2: isBSTUtil(10, -∞, +∞)
root = 10

Check: 10 <= -∞ ? No and 10 >= +∞ ? No → ✅ valid

Recurse:

Left subtree: isBSTUtil(root->left = 5, -∞, 10)

Right subtree: isBSTUtil(root->right = 15, 10, +∞)

Step 3: isBSTUtil(5, -∞, 10)
root = 5

Check: 5 <= -∞ ? No, 5 >= 10 ? No → ✅ valid

Recurse:

Left subtree: isBSTUtil(NULL, -∞, 5) → returns true

Right subtree: isBSTUtil(NULL, 5, 10) → returns true

So this whole call returns true ✅

Step 4: isBSTUtil(15, 10, +∞)
root = 15

Check: 15 <= 10 ? No, 15 >= +∞ ? No → ✅ valid

Recurse:

Left subtree: isBSTUtil(6, 10, 15)

Right subtree: isBSTUtil(20, 15, +∞)

Step 5: isBSTUtil(6, 10, 15)
root = 6

Check: 6 <= 10 ? YES ✅ violates rule

So immediately returns false ❌

Step 6: Backtracking
Since left subtree of node 15 returned false, we don’t need to check further.

isBSTUtil(15, 10, +∞) returns false

isBSTUtil(10, -∞, +∞) returns false

Step 7: Final result
isBST(root) → returns false

main() prints:

csharp
Copy code
This tree is NOT a BST ❌


Step 4: isBSTUtil(15, 10, +∞)

root = 15

Check: 15 <= 10 ? No, 15 >= +∞ ? No → ✅ valid

Recurse:

Left subtree: isBSTUtil(6, 10, 15)
here in this step at  isBSTUtil(6, 10, 15) from where did we got the minVal = 10
ChatGPT said:

Good catch 👍 Let’s carefully see where that 10 came from.

We are at this call:

isBSTUtil(15, 10, +∞)


This happened because earlier, at root = 10, we had this line:

return isBSTUtil(root->left, minVal, root->val) &&
       isBSTUtil(root->right, root->val, maxVal);


For the left subtree of 10, the allowed range was (-∞, 10)

For the right subtree of 10, the allowed range was (10, +∞)

So, when we go into the right subtree (node = 15), the range becomes:

minVal = root->val = 10
maxVal = +∞


That’s why the recursive call is:

isBSTUtil(15, 10, +∞)


Now, inside that call, when we further recurse to the left child of 15 (which is 6), the line:

isBSTUtil(root->left, minVal, root->val)


becomes:

isBSTUtil(6, 10, 15)


Here’s why:

minVal was 10 (inherited from its parent 10 → right subtree must be >10)

maxVal is root->val = 15 (since 6 is in the left subtree of 15, it must be less than 15)

So the range for node 6 is (10, 15).
*/