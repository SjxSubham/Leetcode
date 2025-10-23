class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2){
            string temp = "";
            for(int i = 0; i < s.length()-1; i++){
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                temp.push_back(((a + b) % 10) + '0');
            }
            s = temp;
        }
        return s.length() && s[0] == s[1];
    }
};