/* APPROACH
The solution involves two key steps: triangle validity checking and triangle classification. First, verify if the three sides can form a valid triangle using the triangle inequality theorem, then classify the triangle type based on side equality patterns 

Intuition
For three sides to form a valid triangle, they must satisfy the triangle inequality theorem: the sum of any two sides must be greater than the third side. This gives us three conditions to check: a + b > c, b + c > a, and c + a > b
*/
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];
        
        // Check triangle inequality theorem
        if (a + b <= c || b + c <= a || c + a <= b) {
            return "none";
        }
        
        // Check triangle type based on side equality
        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};

