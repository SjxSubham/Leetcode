class Solution {
public:
    bool isPowerOfThree(int n) {
        // Keep dividing n by 3 while it's greater than 2
        while (n > 2) {
            // If n is not divisible by 3, it's not a power of three
            if (n % 3 != 0) {
                return false;
            }
            // Divide n by 3 to check the next level
            n /= 3;
        }
      
        // After the loop, n should be 1 if it was a power of three
        // (n could be 0, 1, or 2 at this point)
        // Powers of three: 3^0 = 1, 3^1 = 3, 3^2 = 9, etc.
        return n == 1;
    }
};