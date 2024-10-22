class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        deque<TreeNode*> levelQ;
        priority_queue<long long, vector<long long>, greater<long long>> minSumQ;
        levelQ.push_back(root);
        
        while (!levelQ.empty()) {
            long long currLvlSum = 0;
            int lvlSize = levelQ.size();
            while (lvlSize-- > 0) {
                TreeNode* currNode = levelQ.front();
                levelQ.pop_front();
                
                if (currNode->left != nullptr) {
                    levelQ.push_back(currNode->left);
                }
                if (currNode->right != nullptr) {
                    levelQ.push_back(currNode->right);
                }
                currLvlSum += currNode->val;
            }
            
            minSumQ.push(currLvlSum);
            if (minSumQ.size() > k) {
                minSumQ.pop();
            }
        }
        
        return (minSumQ.size() == k) ? minSumQ.top() : -1;
        
    }
};
