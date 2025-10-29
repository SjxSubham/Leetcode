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
    vector<int> rightSideView(TreeNode* root) {
        // unordered_map<int,int>map;
        vector<int>ans;
        int level=-1;
        traverseRightSide(root,level,0,ans);
        return ans;
    }
    void traverseRightSide(TreeNode* root,int &mainLevel,int level, vector<int>&ans){
        if(root==NULL) return ;

        if(mainLevel<level){
            ans.push_back(root->val);
            mainLevel=max(mainLevel,level);
        }

        traverseRightSide(root->right,mainLevel,level+1,ans);
        traverseRightSide(root->left,mainLevel,level+1,ans);
    }
};
