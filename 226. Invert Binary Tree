// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/description/

/*
Intuition:
The goal is to flip the binary tree horizontally, meaning every left child becomes a right child, and every right child becomes a left child.

Approach:
1. If the tree is empty (i.e., root is NULL), we simply return NULL because there's nothing to invert.
2. We get the left and right children of the current node (root). We store these subtrees temporarily in leftSubtree and rightSubtree variables for swapping purposes.
3. We assign the leftSubtree to root->right and the rightSubtree to root->left. This effectively inverts the child nodes at the current node.
4. We then call invertTree recursively on the new left and right children (after the swap) to invert the rest of the tree.
5. Once all nodes are inverted, we return the root node, which now points to the inverted tree.
*/

// Time Complexity: O(n), Space Complexity: O(h)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        // Extract the left Subtree
        TreeNode *leftSubtree = (root->left)? root->left: NULL;
        // Extract the right Subtree
        TreeNode *rightSubtree = (root->right)? root->right: NULL;
        // swap the left and right subtree
        root->left = rightSubtree;
        root->right = leftSubtree;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
