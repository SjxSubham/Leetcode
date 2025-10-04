//Backtracking (DFS)
//This Works
//Build subsets by choosing/not choosing each element
//Time Complexity: O(n * 2^n)
//Space Complexity: O(n) recursion stack (excluding output)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
        if (idx == (int)nums.size()) { 
            ans.push_back(path); 
            return; 
        }
        // not take
        dfs(idx + 1, nums, path, ans);
        // take
        path.push_back(nums[idx]);
        dfs(idx + 1, nums, path, ans);
        path.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, nums, path, ans);
        return ans;
    }
};
