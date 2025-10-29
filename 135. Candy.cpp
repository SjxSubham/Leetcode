class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n, 1);  // Step 1: Initialize with 1

        // Step 2: Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }

        // Step 3: Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                count[i] = max(count[i], count[i + 1] + 1);
            }
        }

        // Step 4: Total candies
        return accumulate(count.begin(), count.end(), 0);
    }
};
