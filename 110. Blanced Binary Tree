 int height(TreeNode* root){
        if(!root)return 0;
        // int leftheight = height(root->left);
        // int rightheight = height(root->right);
        int ans = 1+ max(height(root->left),height(root->right));
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        //1 case
        // int leftHeight = height(root->left);
        // int rightHeight  = height(root->right);
        int diff = abs(height(root->left)-height(root->right));

        //bool ans = (diff <=1);

        //Recursion
        // int leftans = isBalanced(root->left);
        // int rightans = isBalanced(root->right);

        if((diff <=1) && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        else{
            return false;
        }
    }
