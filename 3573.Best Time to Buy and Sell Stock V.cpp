class Solution {
public:
    vector<int> prices;
    long long mn = -1e14;
    vector<vector<vector<long long>>> dp;
    long long f(int i, int k, int state){
        if(i == prices.size()){
            return state == 0 ? 0 : mn;
        }
        if(dp[i][k][state] != mn) return dp[i][k][state];

        long long p = prices[i];
        long long profit = mn;
        profit = max(profit, f(i + 1, k, state));

        if(state == 0){
            profit = max(profit, f(i+1, k, 1) - p);
            profit = max(profit, f(i+1, k, 2) + p);
        }
        else if(k > 0){ // have transactions left
            if(state == 1){
                profit = max(profit, f(i+1, k-1, 0) + p);
                
            }
            else{
                 profit = max(profit, f(i+1, k-1, 0) - p);
            }
        }
        return dp[i][k][state] = profit;
    }
    
    long long maximumProfit(vector<int>& prices, int k) {
        this->prices = prices;
        dp.assign(prices.size() + 1, vector<vector<long long>> (k + 1, vector<long long> (3, mn)));
        return f(0, k, 0);  
    }
};