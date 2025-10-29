class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = 10001;
        int n = nums.size();
        int maxVal = 0;
        vector<int> f(m, 0);
        vector<int> dp(m + 1, 0);

        for (int i = 0; i < n; i++) {
            f[nums[i]]++;
            maxVal = max(maxVal, nums[i]);
        }

        dp[1] = f[1];
        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + f[i] * i);
        }

        return dp[maxVal];
    }
};
