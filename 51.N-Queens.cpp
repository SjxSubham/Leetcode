#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int col, int n, vector<string> &board, 
               vector<vector<string>> &ans, 
               vector<int> &leftrow, vector<int> &upperdiag, vector<int> &lowerdiag) {
        
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && lowerdiag[row + col] == 0 && upperdiag[(n - 1) + (col - row)] == 0) {
                
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdiag[row + col] = 1;
                upperdiag[(n - 1) + (col - row)] = 1;

                solve(col + 1, n, board, ans, leftrow, upperdiag, lowerdiag);

                board[row][col] = '.';  // backtrack
                leftrow[row] = 0;
                lowerdiag[row + col] = 0;
                upperdiag[(n - 1) + (col - row)] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> leftrow(n, 0);
        vector<int> lowerdiag(2 * n - 1, 0);
        vector<int> upperdiag(2 * n - 1, 0);

        solve(0, n, board, ans, leftrow, upperdiag, lowerdiag);
        return ans;
    }
};
