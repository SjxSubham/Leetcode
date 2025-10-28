// Includes Soln to 292. Nim Game Problem
// Using trial and error it can be found that you can win the game for any n less than 4 or if n is not divisible by 4
// This code uses the simple observation to solve the problem


class Solution {
public:
    bool canWinNim(int n) {
        if (n<=3 || n%4!=0) return true;
        return false;
    }
};