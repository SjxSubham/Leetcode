/* Approach

We use **exponentiation by squaring** to efficiently compute x^n:

1. Handle the base cases:
   - If n == 0, return 1.
   - If x == 0, return 0 (unless n is 0).

2. Handle negative powers:
   - If n < 0, compute x^{-n} and return 1/result.

3. For positive powers:
   - If n is even: x^n = (x^(n/2)) * (x^(n/2))
   - If n is odd:  x^n = x * (x^(n-1))

4. Implement iteratively to avoid recursion stack overflow for large n.

Time Complexity: O(log n)  
Space Complexity: O(1) for iterative, O(log n) for recursive
 */

 class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // use long long to handle INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {        // if n is odd
                result *= x;
            }
            x *= x;                  // square x
            N /= 2;                  // divide n by 2
        }
        
        return result;
    }
};

