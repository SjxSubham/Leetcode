//T.C - 8ms
int maxDepth(TreeNode* root) {
            if(!root)return 0;
            int leftHeight = maxDepth(root->left);
            int rightHeight = maxDepth(root->right);
            int ans = max(leftHeight,rightHeight) +1;
            return ans;
        }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left)+maxDepth(root->right);

        int ans = max(op1, max(op2,op3));
        return ans;
    }
