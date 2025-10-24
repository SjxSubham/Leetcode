/* Approach

We use exponentiation by squaring to efficiently compute x^n:

Handle base cases:

If n == 0, return 1.
If x == 0, return 0 (unless n is 0).
Handle negative powers:

If n < 0, compute x^{-n} by inverting x (x = 1/x) and making n positive.
For positive powers:

If n is even: x^n = (x^(n/2)) * (x^(n/2))
If n is odd: x^n = x * (x^(n-1))
Implement iteratively to avoid recursion stack overflow for large n:

While n > 0:
If n is odd, multiply result by x.
Square x and divide n by 2.
Return the accumulated result. */

    class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;      // Convert to long long to handle INT_MIN
        if (N < 0) {          // Handle negative powers
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {   // If the current power is odd
                result *= x;
            }
            x *= x;             // Square x
            N /= 2;             // Divide n by 2
        }

        return result;
    }
};
    