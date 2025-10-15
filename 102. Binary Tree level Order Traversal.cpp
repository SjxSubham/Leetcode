
vector<vector<int>> ans;
         queue<TreeNode*>q;
         if(root == NULL)
         return ans;
    //initially 
    q.push(root);

    while(!q.empty()){
        //a
        vector<int>level;
        int Size = q.size();
        for(int i=0; i<Size; i++){

        TreeNode* temp = q.front();
        q.pop();
        

        if(temp->left != NULL)
        q.push(temp->left);
        
        if(temp->right != NULL)
        q.push(temp->right);
        
        
        level.push_back(temp->val);
        
        }
        ans.push_back(level);
    }
    return ans;
