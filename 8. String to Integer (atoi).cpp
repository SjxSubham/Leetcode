class Solution {
public:
    int myAtoi(string s) {
        int l = s.length();
        int sign = 1, i = 0;
        long long ans = 0;

        // trimming leading spaces
        while (i < l && s[i] == ' ') i++;
        

        // sign check condition
        if (i == l)
            return 0;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+')
            i++;

        // converting characters to integer
        while (i < l && isdigit(s[i])) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            // overflow condition handling
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && (-1 * ans) < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return (int)(ans * sign);
    }
};