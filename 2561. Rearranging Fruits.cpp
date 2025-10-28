

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> freq;
        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> extra1, extra2;
        int minFruit = INT_MAX;

        // Collect unbalanced fruits
        for (auto [fruit, diff] : freq) {
            minFruit = min(minFruit, fruit);
            if (diff % 2 != 0) return -1; // impossible to balance
            int count = abs(diff) / 2;
            if (diff > 0) while (count--) extra1.push_back(fruit);
            else while (count--) extra2.push_back(fruit);
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

        long long cost = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            cost += min((long long)min(extra1[i], extra2[i]), 2LL * minFruit);
        }
        return cost;
    }
};
