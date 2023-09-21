void preorder(TreeNode* root,vector<int> &list){
        if(root == NULL){ 
        return;
        }
        list.push_back(root->val);
        preorder(root->left,list);
        
        preorder(root->right,list);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>list;
        preorder(root,list);
        return list;
    }
