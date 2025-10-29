class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if (buy) {
                        // Either buy now, or skip
                        dp[i][buy][cap] = max(-a[i] + dp[i+1][0][cap],dp[i+1][1][cap]);
                    } else {
                        // Either sell now, or skip
                        dp[i][buy][cap] = max(a[i] +dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};