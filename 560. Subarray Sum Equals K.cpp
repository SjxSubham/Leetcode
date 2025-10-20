/*
Problem: 560. Subarray Sum Equals K (Medium)
Link: https://leetcode.com/problems/subarray-sum-equals-k/

Concepts: Prefix Sum, Hash Map
Difficulty: Medium

Problem Statement:
Given an array of integers nums and an integer k, return the total number of subarrays 
whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Explanation: Subarrays [1,1] and [1,1] sum to 2.

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: Subarrays [1,2] and [3] sum to 3.

Approach - Prefix Sum + Hash Map:
1. Use a hash map to store the frequency of prefix sums encountered.
2. For each element, calculate the cumulative sum (prefix sum).
3. Check if (currentSum - k) exists in the hash map.
   - If yes, it means there are subarrays ending at current index with sum = k.
4. Add the current prefix sum to the hash map.
5. Initialize map with {0: 1} to handle subarrays starting from index 0.

Key Insight:
If prefixSum[i] - prefixSum[j] = k, then sum of subarray from j+1 to i equals k.
Rearranging: prefixSum[j] = prefixSum[i] - k

Time Complexity: O(n) - Single pass through the array
Space Complexity: O(n) - Hash map to store prefix sums
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Hash map to store frequency of prefix sums
        unordered_map<int, int> prefixSumCount;
        
        // Initialize with 0 sum occurring once
        // This handles cases where subarray starts from index 0
        prefixSumCount[0] = 1;
        
        int currentSum = 0;  // Running prefix sum
        int count = 0;       // Count of subarrays with sum = k
        
        // Iterate through each element
        for (int num : nums) {
            // Update the prefix sum
            currentSum += num;
            
            // Check if (currentSum - k) exists in the map
            // If it does, it means there are subarrays ending at current index with sum = k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }
            
            // Add current prefix sum to the map
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
};

/*
Detailed Example Walkthrough:
nums = [1, 2, 3], k = 3

Step-by-step execution:
Initial: prefixSumCount = {0: 1}, currentSum = 0, count = 0

i=0, num=1:
  currentSum = 1
  Check if (1 - 3 = -2) in map? No
  prefixSumCount = {0: 1, 1: 1}
  count = 0

i=1, num=2:
  currentSum = 3
  Check if (3 - 3 = 0) in map? Yes! prefixSumCount[0] = 1
  count = 1 (found subarray [1,2])
  prefixSumCount = {0: 1, 1: 1, 3: 1}

i=2, num=3:
  currentSum = 6
  Check if (6 - 3 = 3) in map? Yes! prefixSumCount[3] = 1
  count = 2 (found subarray [3])
  prefixSumCount = {0: 1, 1: 1, 3: 1, 6: 1}

Final answer: 2

Why this works:
- Subarray sum from index i to j = prefixSum[j] - prefixSum[i-1]
- If this equals k: prefixSum[j] - prefixSum[i-1] = k
- Rearranging: prefixSum[i-1] = prefixSum[j] - k
- So we look for (currentSum - k) in our map!

Another Example:
nums = [1,1,1], k = 2

Step-by-step:
Initial: {0: 1}, currentSum = 0, count = 0

i=0, num=1:
  currentSum = 1
  (1 - 2 = -1) not in map
  {0: 1, 1: 1}, count = 0

i=1, num=1:
  currentSum = 2
  (2 - 2 = 0) in map! count += 1
  {0: 1, 1: 1, 2: 1}, count = 1

i=2, num=1:
  currentSum = 3
  (3 - 2 = 1) in map! count += 1
  {0: 1, 1: 1, 2: 1, 3: 1}, count = 2

Answer: 2 (subarrays [1,1] and [1,1])

Test Cases:
1. nums = [1,1,1], k = 2 → Output: 2
2. nums = [1,2,3], k = 3 → Output: 2
3. nums = [1,-1,0], k = 0 → Output: 3
4. nums = [1], k = 1 → Output: 1
*/
