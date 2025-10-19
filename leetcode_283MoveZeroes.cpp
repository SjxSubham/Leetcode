// LeetCode 283: Move Zeroes
// Solution using Two Pointers (in-place)
// Time Complexity: O(n)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 'insertPos' is the index where the next non-zero element should be placed
        // Use size_t for indexing
        size_t insertPos = 0;
        
        // First pass: move all non-zero elements to the front
        // Use size_t for index 'i' to match nums.size()
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }
        
        // Second pass: fill the rest of the array with zeroes
        // Use size_t for index 'i'
        for (size_t i = insertPos; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

// Helper function to print a vector
void printVector(const vector<int>& nums) {
    cout << "[ ";
    // Range-based for loop is fine here
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

// Main function to test the code with edge cases
int main() {
    Solution sol;
    
    // Test 1: Standard case
    vector<int> nums1 = {0, 1, 0, 3, 12};
    cout << "Test 1 (Standard):" << endl;
    cout << "  Original: "; printVector(nums1);
    sol.moveZeroes(nums1);
    cout << "  Moved:    "; printVector(nums1); // Expected: [ 1 3 12 0 0 ]

    // Test 2: Empty array
    vector<int> nums2 = {};
    cout << "\nTest 2 (Empty Array):" << endl;
    cout << "  Original: "; printVector(nums2);
    sol.moveZeroes(nums2);
    cout << "  Moved:    "; printVector(nums2); // Expected: [ ]

    // Test 3: All zeros
    vector<int> nums3 = {0, 0, 0, 0};
    cout << "\nTest 3 (All Zeros):" << endl;
    cout << "  Original: "; printVector(nums3);
    sol.moveZeroes(nums3);
    cout << "  Moved:    "; printVector(nums3); // Expected: [ 0 0 0 0 ]

    // Test 4: All non-zeros
    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << "\nTest 4 (All
