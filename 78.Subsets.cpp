// Subsets using Backtracking (DFS)
// -------------------------------
// Intuition: Each element can be either taken or not taken → 2^n subsets
// Approach: Use DFS recursion with backtracking to explore both choices
// Time Complexity: O(n * 2^n)
// Space Complexity: O(n) recursion stack (excluding output)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        if (idx == (int)nums.size()) { 
            ans.push_back(path); 
            return; 
        }
        // Choice 1: not take nums[idx]
        dfs(idx + 1, nums, path, ans);

        // Choice 2: take nums[idx]
        path.push_back(nums[idx]);
        dfs(idx + 1, nums, path, ans);

        path.pop_back(); // backtrack (undo choice)
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;  
        vector<int> path;        
        dfs(0, nums, path, ans);  
        return ans;
    }
};
