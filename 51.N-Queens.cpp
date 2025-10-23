#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col, vector<string> &temp, int n) {
        int duprow = row;
        int dupcol = col;
        // Check all columns to the left in the same row
        for (int j = 0; j < col; j++) {
            if (temp[row][j] == 'Q') return false;
        }

        // Check upper-left diagonal
        while(row >= 0 && col >= 0){
            if(temp[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        // Check lower-left diagonal
        while(row < n && col >= 0){
            if(temp[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    // Backtracking function to place queens column by column
    void solve(int col, vector<string> temp, vector<vector<string>> &ans, int n) {
        // If all columns are filled, add current board to answer
        if (col == n) {
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, temp, n)) {
                // Place queen
                temp[row][col] = 'Q';
                // Recurse for next column
                solve(col + 1, temp, ans, n); 
                // Backtrack and remove queen
                temp[row][col] = '.';        
            }
        }
    }

    // Main function to call backtracking
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> temp;
    string s(n, '.');
    for(int i = 0 ; i < n ; i++) temp.push_back(s); // FIXED

    solve(0, temp, ans, n);
    return ans;
}

};