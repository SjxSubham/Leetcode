/*
Problem: 300. Longest Increasing Subsequence (Medium)
Link: https://leetcode.com/problems/longest-increasing-subsequence/

Concepts: Dynamic Programming, Binary Search
Difficulty: Medium

Problem Statement:
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Approach 1 - Dynamic Programming (O(n²)):
1. Create a dp array where dp[i] represents the length of LIS ending at index i.
2. For each element, check all previous elements and update dp[i] if nums[i] > nums[j].
3. Return the maximum value in dp array.

Approach 2 - Binary Search + DP (O(n log n)) - Optimized:
1. Maintain a vector 'sub' that stores the smallest tail element for all increasing subsequences.
2. For each number, use binary search to find the position where it should be placed.
3. If the number is larger than all elements in sub, append it.
4. Otherwise, replace the first element that is >= current number.
5. The length of sub at the end is the answer.

Time Complexity: 
- Approach 1: O(n²)
- Approach 2: O(n log n)
Space Complexity: O(n) for both approaches
*/

#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Dynamic Programming - O(n²)
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        // dp[i] = length of LIS ending at index i
        vector<int> dp(n, 1);
        int maxLength = 1;
        
        // For each element
        for (int i = 1; i < n; i++) {
            // Check all previous elements
            for (int j = 0; j < i; j++) {
                // If current element is greater, we can extend the subsequence
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};

// Approach 2: Binary Search + DP - O(n log n) - OPTIMIZED
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // sub[i] = smallest tail element for all increasing subsequences of length i+1
        vector<int> sub;
        
        for (int num : nums) {
            // Use binary search to find the position where num should be placed
            // lower_bound returns iterator to first element >= num
            auto it = lower_bound(sub.begin(), sub.end(), num);
            
            if (it == sub.end()) {
                // num is larger than all elements in sub, append it
                sub.push_back(num);
            } else {
                // Replace the first element >= num
                // This maintains smaller tail values for subsequences
                *it = num;
            }
        }
        
        // The size of sub is the length of LIS
        return sub.size();
    }
};

/*
Why the Binary Search approach works:

The key insight is that we want to keep the tail of each subsequence as small as possible.
This gives us more flexibility to extend subsequences later.

Example: nums = [10,9,2,5,3,7,101,18]

sub array evolution:
- [10]
- [9] (replace 10 with 9, better tail for length 1)
- [2] (replace 9 with 2, even better tail)
- [2,5]
- [2,3] (replace 5 with 3, better tail for length 2)
- [2,3,7]
- [2,3,7,101]
- [2,3,7,18] (replace 101 with 18, better tail for length 4)

Final answer: 4

Important Note:
- The sub array doesn't necessarily contain the actual LIS.
- It contains the best (smallest) tail values for each length.
- But its size equals the length of the LIS!

Test Cases:
1. nums = [10,9,2,5,3,7,101,18] → Output: 4
2. nums = [0,1,0,3,2,3] → Output: 4
3. nums = [7,7,7,7,7,7,7] → Output: 1
4. nums = [1,3,6,7,9,4,10,5,6] → Output: 6
*/
