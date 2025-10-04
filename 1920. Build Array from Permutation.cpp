// ---------------- Approach ----------------
//
// - We are directly asked to create a new array `ans` such that:
//       ans[i] = nums[nums[i]]
// - Since nums is guaranteed to be a valid permutation (all elements in [0..n-1] without duplicates),
//   the indexing nums[nums[i]] is always valid.
// - Just iterate through `nums` and build `ans`.
//
// Time Complexity: O(n)
// Space Complexity: O(n) for the output array


// ---------------- Intuition ----------------
//
// The problem is a straightforward application of indexing.
// Each element at position i is mapped to the value at nums[i],
// and then we fetch nums[nums[i]].
// 
// Example: nums = [0,2,1,5,3,4]
//   ans[0] = nums[nums[0]] = nums[0] = 0
//   ans[1] = nums[nums[1]] = nums[2] = 1
//   ans[2] = nums[nums[2]] = nums[1] = 2
//   ...
// Result: ans = [0,1,2,4,5,3]


// ---------------- Solution in Code ----------------

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
