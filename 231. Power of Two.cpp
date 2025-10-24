// ---------------- Approach ----------------
//
// - A number n is a power of two if:
//     - n > 0
//     - In binary representation, it has exactly one set bit.
//
// - Trick: For powers of two, `n & (n - 1)` = 0
//   Example: n = 8 (1000), n-1 = 7 (0111), AND = 0000
//
// - This works because subtracting 1 flips all bits after the rightmost set bit.
// - If n has more than one set bit, the result won’t be zero.


// ---------------- Intuition ----------------
//
// Binary representation of powers of two looks like:
//   1 (0001), 2 (0010), 4 (0100), 8 (1000), 16 (10000) ...
// Only one bit is set to 1.
//
// Thus, checking `(n > 0) && (n & (n - 1)) == 0` is the most efficient way.


// ---------------- Solution in Code ----------------

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};
