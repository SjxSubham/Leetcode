// LeetCode Problem #217: Contains Duplicate
// Difficulty: Easy
// Link: https://leetcode.com/problems/contains-duplicate/

/*
Problem Description:
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation: The element 1 appears at index 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation: All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
*/

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Checks if array contains any duplicate values.
     * 
     * Algorithm: Hash Set
     * - Use an unordered_set to track seen numbers
     * - For each number, check if it's already in the set
     * - If yes, we found a duplicate
     * - If no, add it to the set and continue
     * 
     * @param nums Vector of integers to check
     * @return true if any duplicates exist, false otherwise
     * 
     * Time Complexity: O(n) - Single pass through array with O(1) set operations
     * Space Complexity: O(n) - Hash set stores unique elements
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            // If number already exists in set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Otherwise, add it to the set
            seen.insert(num);
        }
        
        // No duplicates found
        return false;
    }
};

// Helper function to print test results
void printResult(vector<int>& nums, bool expected) {
    Solution sol;
    bool result = sol.containsDuplicate(nums);
    
    cout << "Input: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Status: " << (result == expected ? "PASS ✓" : "FAIL ✗") << endl;
    cout << "-------------------" << endl;
}

int main() {
    cout << "LeetCode #217: Contains Duplicate" << endl;
    cout << "==================================" << endl << endl;
    
    // Test Case 1: Has duplicate
    vector<int> test1 = {1, 2, 3, 1};
    printResult(test1, true);
    
    // Test Case 2: No duplicates
    vector<int> test2 = {1, 2, 3, 4};
    printResult(test2, false);
    
    // Test Case 3: Multiple duplicates
    vector<int> test3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    printResult(test3, true);
    
    // Test Case 4: Single element
    vector<int> test4 = {1};
    printResult(test4, false);
    
    // Test Case 5: Two same elements
    vector<int> test5 = {5, 5};
    printResult(test5, true);
    
    // Test Case 6: Negative numbers with duplicates
    vector<int> test6 = {-1, -2, -3, -1};
    printResult(test6, true);
    
    // Test Case 7: Large array no duplicates
    vector<int> test7 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printResult(test7, false);
    
    return 0;
}

/*
Expected Output:
==================================
LeetCode #217: Contains Duplicate
==================================

Input: [1,2,3,1]
Output: true
Expected: true
Status: PASS ✓
-------------------
Input: [1,2,3,4]
Output: false
Expected: false
Status: PASS ✓
-------------------
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
Expected: true
Status: PASS ✓
-------------------
Input: [1]
Output: false
Expected: false
Status: PASS ✓
-------------------
Input: [5,5]
Output: true
Expected: true
Status: PASS ✓
-------------------
Input: [-1,-2,-3,-1]
Output: true
Expected: true
Status: PASS ✓
-------------------
Input: [1,2,3,4,5,6,7,8,9,10]
Output: false
Expected: false
Status: PASS ✓
-------------------

Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash set storing unique elements

Algorithm Explanation (Hash Set):
1. Use an unordered_set to store numbers we've seen
2. For each number in the array:
   - Check if it's already in the set
   - If yes → found duplicate, return true
   - If no → add it to the set, continue
3. If we finish the loop without finding duplicates, return false

Why Hash Set?
- O(1) average time for insert and lookup operations
- Automatically handles uniqueness
- More efficient than sorting (O(n log n)) or nested loops (O(n²))
*/
