// quite Hard
  bool code(TreeNode*left, TreeNode*right){
        if(!left && !right)return true;
        if((left && !right) || (!left && right) || (left->val != right->val))return false;
        return code(left->left,right->right) && code(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return code(root,root);

              
    }
