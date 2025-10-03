class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check three conditions:
        // 1. n > 0: Power of 4 must be positive
        // 2. (n & (n - 1)) == 0: Check if n is a power of 2
        //    - Powers of 2 have only one bit set in binary representation
        //    - Subtracting 1 flips all bits after the single set bit
        //    - AND operation results in 0 for powers of 2
        // 3. (n & 0xAAAAAAAA) == 0: Ensure the single bit is at an even position
        //    - 0xAAAAAAAA = 10101010101010101010101010101010 in binary
        //    - This mask has bits set at odd positions (0-indexed)
        //    - Powers of 4 have their single bit at even positions (bit 0, 2, 4, 6...)
        //    - AND with this mask should be 0 for powers of 4
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }
};
