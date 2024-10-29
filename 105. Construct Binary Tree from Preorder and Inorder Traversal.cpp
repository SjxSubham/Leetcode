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
    unordered_map<int,int> mp;
    TreeNode* build(int il,int ir,int pl,int pr,vector<int> &preorder,vector<int> &inorder){
        if(il>ir) return NULL;
        TreeNode* cur_node = new TreeNode(preorder[pl]);
        if(il==ir) return cur_node;
        int inorder_ind = mp[preorder[pl]];
        int m = pl+inorder_ind-il;
        cur_node->left = build(il,inorder_ind-1,pl+1,m,preorder,inorder);
        cur_node->right = build(inorder_ind+1,ir,m+1,pr,preorder,inorder);
        return cur_node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return build(0,n-1,0,n-1,preorder,inorder);
    }
};
