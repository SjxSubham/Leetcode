// T.C - 0 ms
 int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = max(leftHeight,rightHeight) +1;
        return ans;
    }
