class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char chr : s) {
            if (chr == '(' || chr == '[' || chr == '{') {       //open bracket being pushed to the stack if found
                stk.push(chr);
            } 
            else {
                
                //checking for empty stack before popping or comparison
                if (stk.empty()) {              
                    return false;
                }

                //getting most recent open bracket and popping for the comparison
                char top = stk.top();
                stk.pop();

                // Verify the closing bracket 'chr' matches the popped open bracket 'top'...
                if (chr == ')' && top != '(') {
                    return false;
                }
                if (chr == ']' && top != '[') {
                    return false;
                }
                if (chr == '}' && top != '{') {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};