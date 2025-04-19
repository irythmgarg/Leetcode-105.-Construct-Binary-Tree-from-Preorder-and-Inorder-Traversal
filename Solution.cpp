/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // Helper function to find the index of a value in inorder traversal
    int findindex(vector<int>& inorder, int value, int instart, int inend) {
        for (int i = instart; i <= inend; i++) {
            if (inorder[i] == value)
                return i;
        }
        return -1; // Value not found (shouldn't happen with valid input)
    }

    // Recursive function to build tree from preorder and inorder
    TreeNode* maketree(vector<int>& preorder, vector<int>& inorder,
                       int prestart, int preend, int instart, int inend) {

        // Base case: no elements to construct the tree
        if (prestart > preend || instart > inend)
            return NULL;

        // The first element in preorder is the root
        TreeNode* node = new TreeNode(preorder[prestart]);

        // Find the index of this root in inorder traversal
        int ind = findindex(inorder, preorder[prestart], instart, inend);
        int index = ind - instart;  // Number of nodes in the left subtree

        // Recursively construct the left and right subtrees
        node->left = maketree(preorder, inorder, prestart + 1, prestart + index, instart, ind - 1);
        node->right = maketree(preorder, inorder, prestart + index + 1, preend, ind + 1, inend);

        return node;
    }

    // Main function to be called
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return maketree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
