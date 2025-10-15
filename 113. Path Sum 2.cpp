void solve(TreeNode* root,int targetSum,int &currsum,vector<int>&path,  vector<vector<int>>&ans){
    if(root == NULL){
        return;
    }
    //leaf node
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->val);
        currsum += root->val;
        if(currsum == targetSum){
            ans.push_back(path);
        }
        //exceptional
        path.pop_back();
        currsum -= root->val;
        return;
    }
    //include curr node
    path.push_back(root->val);
    currsum += root->val;

    solve(root->left,targetSum,currsum,path,ans);
    solve(root->right,targetSum,currsum,path,ans);

    //exceptional backtrack, aslo can be done without this
    path.pop_back();
    currsum -= root->val;

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>>ans;
         int sum =0;
         vector<int>path;
         solve(root,targetSum, sum ,path,ans);
         return ans;

    }
