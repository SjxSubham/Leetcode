// Problem: 20. Valid Parentheses
// Language: C++
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)
// Explanation:
// We use a stack to store opening brackets. For each closing bracket,
// we check if it matches the top of the stack. If all brackets are matched,
// the string is valid.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto &ch : s) {
            if (ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                    return false;
            }
        }
        return st.empty();
    }
};

/*
Example:
Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false
*/
