class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if numRows is 1 or greater than string length, return original string
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        // Create a vector to store characters for each row
        vector<string> rows(numRows);
        
        // Track current row and direction
        int currentRow = 0;
        bool goingDown = false;
        
        // Iterate through each character in the string
        for (char c : s) {
            // Add character to current row
            rows[currentRow] += c;
            
            // Change direction when we hit top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to next row based on direction
            currentRow += goingDown ? 1 : -1;
        }
        
        // Concatenate all rows to get final result
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};

// Test cases
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution solution;
    
    // Example 1
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Input: s = \"" << s1 << "\", numRows = " << numRows1 << endl;
    cout << "Output: \"" << solution.convert(s1, numRows1) << "\"" << endl;
    cout << "Expected: \"PAHNAPLSIIGYIR\"\n" << endl;
    
    // Example 2
    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Input: s = \"" << s2 << "\", numRows = " << numRows2 << endl;
    cout << "Output: \"" << solution.convert(s2, numRows2) << "\"" << endl;
    cout << "Expected: \"PINALSIGYAHRPI\"\n" << endl;
    
    // Example 3
    string s3 = "A";
    int numRows3 = 1;
    cout << "Input: s = \"" << s3 << "\", numRows = " << numRows3 << endl;
    cout << "Output: \"" << solution.convert(s3, numRows3) << "\"" << endl;
    cout << "Expected: \"A\"" << endl;
    
    return 0;
}
