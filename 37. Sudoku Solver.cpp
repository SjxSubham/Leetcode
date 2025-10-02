class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

private:
    bool backtrack(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch;
                            if (backtrack(board)) return true; // continue with this placement
                            board[r][c] = '.'; // undo if failed
                        }
                    }
                    return false; // no valid digit, backtrack
                }
            }
        }
        return true; // all cells filled
    }

    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        // Row & Column check
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;
            if (board[i][c] == ch) return false;
        }
        // 3x3 sub-box check
        int startRow = (r / 3) * 3;
        int startCol = (c / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == ch) return false;
            }
        }
        return true;
    }
};