class Solution {
public:

    int minFlipsMonoIncr(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        if(s[0]=='0'){
            dp[0][0]=0;
            dp[0][1]=1;

        }
        else{
              dp[0][0]=1;
            dp[0][1]=0;
        }
        for(int i=1;i<n;i++){
               dp[i][0]=dp[i-1][0]+(s[i]=='0'?0:1);
               dp[i][1]=min(dp[i-1][0],dp[i-1][1])+(s[i]=='1'?0:1);

        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};