// LeetCode Problem #136: Single Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/single-number/

/*
Problem Description:
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

You must implement a solution with a linear runtime complexity and use only constant 
extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
- 1 <= nums.length <= 3 * 10^4
- -3 * 10^4 <= nums[i] <= 3 * 10^4
- Each element in the array appears twice except for one element which appears only once.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Finds the single number that appears only once in the array.
     * 
     * Algorithm: XOR Bit Manipulation
     * - XOR of two same numbers is 0 (a ^ a = 0)
     * - XOR of a number with 0 is the number itself (a ^ 0 = a)
     * - XOR is commutative and associative
     * - So XOR of all numbers will cancel out duplicates and leave the single number
     * 
     * @param nums Vector of integers where all except one appear twice
     * @return The single number that appears only once
     * 
     * Time Complexity: O(n) - Single pass through the array
     * Space Complexity: O(1) - No extra space used
     */
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // XOR all numbers together
        // Duplicates will cancel out (a ^ a = 0)
        // Single number will remain (a ^ 0 = a)
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
};

// Helper function to print test results
void printResult(vector<int>& nums, int expected) {
    Solution sol;
    int result = sol.singleNumber(nums);
    
    cout << "Input: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "Status: " << (result == expected ? "PASS ✓" : "FAIL ✗") << endl;
    cout << "-------------------" << endl;
}

int main() {
    cout << "LeetCode #136: Single Number" << endl;
    cout << "=============================" << endl << endl;
    
    // Test Case 1: Basic case
    vector<int> test1 = {2, 2, 1};
    printResult(test1, 1);
    
    // Test Case 2: More numbers
    vector<int> test2 = {4, 1, 2, 1, 2};
    printResult(test2, 4);
    
    // Test Case 3: Single element
    vector<int> test3 = {1};
    printResult(test3, 1);
    
    // Test Case 4: Negative numbers
    vector<int> test4 = {-1, -1, -2, -2, 5};
    printResult(test4, 5);
    
    // Test Case 5: Large array
    vector<int> test5 = {1, 3, 1, 5, 3, 5, 7};
    printResult(test5, 7);
    
    // Test Case 6: Zero in array
    vector<int> test6 = {0, 1, 0};
    printResult(test6, 1);
    
    return 0;
}

/*
Expected Output:
=============================
LeetCode #136: Single Number
=============================

Input: [2,2,1]
Output: 1
Expected: 1
Status: PASS ✓
-------------------
Input: [4,1,2,1,2]
Output: 4
Expected: 4
Status: PASS ✓
-------------------
Input: [1]
Output: 1
Expected: 1
Status: PASS ✓
-------------------
Input: [-1,-1,-2,-2,5]
Output: 5
Expected: 5
Status: PASS ✓
-------------------
Input: [1,3,1,5,3,5,7]
Output: 7
Expected: 7
Status: PASS ✓
-------------------
Input: [0,1,0]
Output: 1
Expected: 1
Status: PASS ✓
-------------------

Time Complexity: O(n) where n is the length of the array
Space Complexity: O(1) - constant extra space

Algorithm Explanation (XOR Bit Manipulation):
1. XOR has special properties:
   - a ^ a = 0 (XOR of same numbers is 0)
   - a ^ 0 = a (XOR with 0 gives the number itself)
   - XOR is commutative: a ^ b = b ^ a
   - XOR is associative: (a ^ b) ^ c = a ^ (b ^ c)

2. When we XOR all numbers together:
   - All duplicate numbers cancel out to 0
   - The single number XORed with 0 gives the single number

Example: [4,1,2,1,2]
4 ^ 1 ^ 2 ^ 1 ^ 2 = 4 ^ (1 ^ 1) ^ (2 ^ 2) = 4 ^ 0 ^ 0 = 4
*/
