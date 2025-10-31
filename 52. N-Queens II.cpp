/*Approach
NOTE-PLEASE READ APPROACH FIRST THEN SEE THE CODE. YOU WILL DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.

Approach for this Problem:

1. Initialize a counter to keep track of the total number of valid N-Queens solutions.
2. Use three sets to track attacks:
   - cols: columns where queens are already placed
   - diag: main diagonals under attack (row + col)
   - anti_diag: anti-diagonals under attack (row - col)
3. Create a recursive backtracking function that tries to place a queen row by row.
4. For each row, iterate through all columns and check if placing a queen at (row, col) is safe (not in cols, diag, or anti_diag).
5. If safe, mark the column and diagonals as occupied and recurse to the next row.
6. After recursion, backtrack by unmarking the column and diagonals to explore other possibilities.
7. When row == n, increment the counter because a valid configuration is found.
8. Return the counter after exploring all possibilities.

Complexity
Time complexity: O(n!) - because we try n positions for the first row, n-1 for the next, and so on.
Space complexity: O(n) - for the recursion stack and sets used to track attacks.
*/

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0; // step 1: initialize solution counter

        unordered_set<int> cols;      // step 2: columns under attack
        unordered_set<int> diag;      // step 2: main diagonals under attack
        unordered_set<int> anti_diag; // step 2: anti-diagonals under attack

        // step 3: recursive backtracking function
        function<void(int)> backtrack = [&](int row) {
            if(row == n){ // step 7: valid configuration found
                count++;
                return;
            }

            // step 4: iterate through columns for current row
            for(int col = 0; col < n; col++){
                if(cols.count(col) || diag.count(row + col) || anti_diag.count(row - col))
                    continue; // not safe, skip

                // step 5: place queen and mark attacks
                cols.insert(col);
                diag.insert(row + col);
                anti_diag.insert(row - col);

                backtrack(row + 1); // recurse to next row

                // step 6: backtrack, unmark attacks
                cols.erase(col);
                diag.erase(row + col);
                anti_diag.erase(row - col);
            }
        };

        backtrack(0); // start from row 0
        return count; // step 8: return total solutions
    }
};
