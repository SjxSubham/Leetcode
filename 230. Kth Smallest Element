


    int kthSmallest(TreeNode* root, int &k) {   // by reference pass krna pdega, track krney ke liye
       if(!root)  return -1;
       // LNR Inorder  Traversal
       int leftAns =  kthSmallest(root->left,k);
       if(leftAns != -1){
           return leftAns;
       }
       //N
       k--;
       if(k == 0 ){
           return root->val;
       }
       //R
       int rightAns = kthSmallest(root->right,k);
       return rightAns;
    }
};
