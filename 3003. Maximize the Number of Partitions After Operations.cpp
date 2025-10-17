class Solution {
public:
    typedef long long ll;
    unordered_map<long long, int> dp;
    ll solve(ll i, ll mask, ll change, int k, string& s) {

        int n = s.size();
        if (i == n) {
            return 1;
        }

        ll currState = (i << 27) | (mask << 1) | (change);

        if (dp.find(currState) != dp.end()) {
            return dp[currState];
        }

        int val = s[i] - 'a';
        ll newMask = mask | (1 << val);

        int count = __builtin_popcount(newMask);

        ll ans = 0;
        ll maxi = 0;

        if (count > k) {
            ans = 1 + solve(i + 1, 1 << val, change, k, s);
            maxi = max(maxi, ans);
        } else {
            ans = solve(i + 1, newMask, change, k, s);
            maxi = max(maxi, ans);
        }

        if (change) {
            return dp[currState] = maxi;
        }

        for (int j = 0; j < 26; j++) {

            ll newMask = mask | (1 << j);
            ll count = __builtin_popcount(newMask);

            if (count > k) {
                maxi = max(maxi, 1 + solve(i + 1, 1 << j, 1, k, s));
            } else {
                maxi = max(maxi, solve(i + 1, newMask, 1, k, s));
            }
        }

        return dp[currState] = maxi;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return solve(0, 0, 0, k, s);
    }
};
