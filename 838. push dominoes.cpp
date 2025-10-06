/*
838. Push Dominoes
Problem: https://leetcode.com/problems/push-dominoes/

Approach:
- Process forces propagating from both left and right
- For each position track timing and direction of forces
- Compare forces to determine final state

Intuition:
- Use two arrays to track forces from left and right 
- For each domino, compare which force reaches first
- If forces arrive at same time, they cancel out

Solution:
*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);
        
        // Process right forces
        int time = 0;
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'R') {
                time = 0;
            } else if(dominoes[i] == 'L') {
                time = INT_MAX;
            } else if(time != INT_MAX) {
                right[i] = ++time;
            }
        }
        
        // Process left forces
        time = 0;
        for(int i = n-1; i >= 0; i--) {
            if(dominoes[i] == 'L') {
                time = 0;
            } else if(dominoes[i] == 'R') {
                time = INT_MAX;
            } else if(time != INT_MAX) {
                left[i] = ++time;
            }
        }
        
        // Determine final state
        string result = dominoes;
        for(int i = 0; i < n; i++) {
            if(left[i] < right[i]) {
                result[i] = 'L';
            } else if(right[i] < left[i]) {
                result[i] = 'R';
            }
        }
        
        return result;
    }
};
