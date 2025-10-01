class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i + 1] + nums[i + 2] > nums[i]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        return 0; 
    }
};

/* 
Alternative Approach - Same Logic, Different Implementation:
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());  // Sort in descending order
        
        for (int i = 0; i <= (int)nums.size() - 3; i++) {
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];
            
            // Triangle inequality: a + b > c, b + c > a, a + c > b
            // Since a >= b >= c, we only need to check b + c > a
            if (b + c > a) {
                return a + b + c;
            }
        }
        
        return 0;
    }
};

Problem Explanation:
- Find the largest perimeter of a triangle that can be formed from the array
- Triangle inequality: sum of any two sides must be greater than the third side
- For sides a >= b >= c: only need to check if b + c > a

Strategy:
1. Sort array in descending order
2. Check triplets from largest to smallest
3. Return first valid triangle's perimeter (guaranteed to be largest)
4. If no valid triangle exists, return 0

Example: nums = [2,1,2]
- Sorted: [2,2,1]
- Check (2,2,1): 2+1 > 2? Yes! → Return 2+2+1 = 5

Example: nums = [1,2,1]
- Sorted: [2,1,1] 
- Check (2,1,1): 1+1 > 2? No!
- No more triplets → Return 0

Time Complexity: O(n log n) - dominated by sorting
Space Complexity: O(1) - only using constant extra space
*/