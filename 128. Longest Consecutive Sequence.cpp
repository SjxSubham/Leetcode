/*
Problem: 128. Longest Consecutive Sequence (Medium)
Link: https://leetcode.com/problems/longest-consecutive-sequence/

Concepts: Hashing, Array
Difficulty: Medium

Problem Statement:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Approach:
1. Use an unordered_set to store all numbers for O(1) lookup time.
2. For each number, check if it's the start of a sequence (num-1 not in set).
3. If it's the start, count consecutive numbers by incrementing and checking if they exist in the set.
4. Keep track of the maximum length found.
5. This ensures we only traverse each sequence once, giving us O(n) time complexity.

Time Complexity: O(n) - We visit each number at most twice
Space Complexity: O(n) - For storing numbers in the hash set
*/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Edge case: empty array
        if (nums.empty()) return 0;
        
        // Step 1: Insert all numbers into a hash set for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLength = 0;
        
        // Step 2: Iterate through each number
        for (int num : numSet) {
            // Step 3: Check if this number is the start of a sequence
            // A number is the start if (num - 1) doesn't exist in the set
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;
                
                // Step 4: Count the length of the consecutive sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }
                
                // Step 5: Update the maximum length
                maxLength = max(maxLength, currentLength);
            }
        }
        
        return maxLength;
    }
};

/*
Why this solution works:
- By using a hash set, we achieve O(1) lookup time for checking if a number exists.
- We only start counting from the beginning of each sequence (when num-1 doesn't exist).
- This prevents counting the same sequence multiple times.
- Each number is visited at most twice: once in the outer loop and possibly once when counting.
- Therefore, the overall time complexity is O(n).

Test Cases:
1. nums = [100,4,200,1,3,2] → Output: 4
2. nums = [0,3,7,2,5,8,4,6,0,1] → Output: 9
3. nums = [] → Output: 0
4. nums = [1] → Output: 1
*/
