class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        long long ans=0;
        while(i<n && isdigit(s[i])){
            ans = ans*10 + (s[i]-'0');
            if(sign==1 && ans>INT_MAX) return INT_MAX;
            if(sign==-1 && -ans<INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(sign*ans);
    }
};
