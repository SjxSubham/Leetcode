//simple c++ approach
//T.C- O(n)
//Stack class 3
//HARD question

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxlen =0;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()) {
                    st.push(i);  //hard area
                }
                else{
                    int len = i - st.top();
                    maxlen = max(len,maxlen);
                }
            }
        }
        return maxlen;
    }
};
