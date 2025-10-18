// Same as Lca of a Binary tree
if(!root)return NULL;

        //Base Case
        if(root->val == p->val)return p;
        if(root->val == q->val)return q;

        //Recursion
        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);

        if(!leftans && !rightans)return NULL;
        else if(!leftans && rightans)return rightans;
        else if(leftans && !rightans)return leftans;
        else{
            return root;
        }
