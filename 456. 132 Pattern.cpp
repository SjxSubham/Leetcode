#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false; // Not enough numbers to form a 132 pattern

        // Stack to store potential candidates for the "3" element in the 132 pattern
        stack<int> st;
        // Variable to keep track of the maximum "2" element we have seen so far
        int thirdElement = INT_MIN;

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // If we find a number that is less than the current "2" element, we have found a 132 pattern
            if (nums[i] < thirdElement) {
                return true;
            }

            // Maintain the stack to ensure the top always represents a potential "2" element.
            while (!st.empty() && nums[i] > st.top()) {
                thirdElement = st.top();
                st.pop();
            }

            // Push the current element as a potential "3"
            st.push(nums[i]);
        }

        // If no pattern is found, return false
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 4, 2};
    bool result = solution.find132pattern(nums);
    if (result) {
        cout << "132 pattern found!" << endl;
    } else {
        cout << "No 132 pattern found." << endl;
    }
    
    return 0;
}
