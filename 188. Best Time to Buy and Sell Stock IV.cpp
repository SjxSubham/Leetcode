class Solution {
public:
    vector<vector<vector<int>>> dp;

    int profit(vector<int>& prices, int i, int isBuy, int k) {
        if (i == prices.size() || k == 0) return 0;

        if (dp[i][isBuy][k] != -1) return dp[i][isBuy][k];

        int a, b;
        if (isBuy) {
            a = profit(prices, i + 1, 1, k);
            b = profit(prices, i + 1, 0, k) - prices[i];
        } else {
            a = profit(prices, i + 1, 0, k);
            b = profit(prices, i + 1, 1, k - 1) + prices[i];
        }

        return dp[i][isBuy][k] = max(a, b);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return profit(prices, 0, 1, k);
    }
};