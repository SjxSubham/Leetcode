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
        int insertPos = 0;
        
        // First pass: move all non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }
        
        // Second pass: fill the rest of the array with zeroes
        for (int i = insertPos; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

// Helper function to print a vector
void printVector(const vector<int>& nums) {
    cout << "[ ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

// Main function to test the code
int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    
    cout << "Original array: ";
    printVector(nums);
    
    sol.moveZeroes(nums);
    
    cout << "Array after moving zeroes: ";
    printVector(nums); // Should be [ 1 3 12 0 0 ]

    return 0;
}
