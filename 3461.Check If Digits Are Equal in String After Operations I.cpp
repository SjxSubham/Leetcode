/* Approach: Simulation

Intuition:

Since the data size in this problem is very small, 
we can directly simulate the operations described in the problem.

Each time an operation is performed, the string length decreases by one. 
Because the problem asks whether the final two digits of the string are the same, 
we need to perform a total of n−2 operations, where n is the initial string length.

In each operation, we start from the beginning of the string, 
add two adjacent digits (say, the characters at positions j and j+1), 
take the result modulo 10, and store the obtained value at position j. 
This process does not affect the remaining parts of the current operation and prepares the string for the next iteration.*/

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 0; j <= n - 1 - i; j++) {
                s[j] = ((s[j] - '0') + (s[j + 1] - '0')) % 10 + '0';
            }
        }
        return s[0] == s[1];
    }
};