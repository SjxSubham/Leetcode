class Solution
{
    public:
        int coinChange(vector<int> &coins, int n)
        {
            int dp[++n];
            dp[0] = 0;
            sort(begin(coins), end(coins));
            for (int i = 1; i < n; i++)
            {
                dp[i] = INT_MAX;
                for (int c : coins)
                {
                    if (i - c < 0)
                        break;
                    if (dp[i - c] != INT_MAX)
                        dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
            return dp[--n] == INT_MAX ? -1 : dp[n];
        }
};
