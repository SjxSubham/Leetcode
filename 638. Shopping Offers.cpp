/*
 * Shopping Offers (DFS + Memoization)
 *
 * Description:
 * In LeetCode Store, there are n items to buy. Each has a normal price.
 * Some special bundle offers let you buy multiple items together at a discount.
 * You want to get all items in your "needs" list at the lowest total cost.
 *
 * Approach:
 * - Use recursion (DFS) to try all ways of buying:
 *     1. Buy items one-by-one at regular prices.
 *     2. Try each special offer (if it doesn't exceed the needs).
 * - Memoize the result for each unique "needs" state to avoid recomputation.
 *
 * Steps:
 * 1. Define a helper function dfs(currentNeeds) → minimum cost for these needs.
 * 2. Base cost = sum(need[i] * price[i]).
 * 3. For each special offer:
 *      - Check if we can apply it (doesn't exceed needs).
 *      - If yes, subtract items and call dfs() recursively.
 * 4. Memoize and return the minimum cost found.
 *
 * Time Complexity: O(n * product(needs[i]))  (worst case)
 * Space Complexity: O(product(needs[i]))     (for memoization)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> memo; // memoization cache

    // Convert current needs to a string key for memo
    string encode(vector<int>& needs) {
        string key;
        for (int num : needs) key += to_string(num) + ",";
        return key;
    }

    // Recursive function to find the minimum cost
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];

        int n = price.size();
        int cost = 0;

        // Base case: buy all items individually
        for (int i = 0; i < n; i++) {
            cost += needs[i] * price[i];
        }

        // Try applying each special offer
        for (auto& offer : special) {
            vector<int> newNeeds = needs;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                newNeeds[i] -= offer[i];
                if (newNeeds[i] < 0) { // can't buy more than needed
                    valid = false;
                    break;
                }
            }

            if (valid) {
                cost = min(cost, offer[n] + dfs(price, special, newNeeds));
            }
        }

        memo[key] = cost;
        return cost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        memo.clear();
        return dfs(price, special, needs);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> price1 = {2, 5};
    vector<vector<int>> special1 = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs1 = {3, 2};
    cout << "Test Case 1: " << sol.shoppingOffers(price1, special1, needs1) << endl; // 14

    // Test Case 2
    vector<int> price2 = {2, 3, 4};
    vector<vector<int>> special2 = {{1, 1, 0, 4}, {2, 2, 1, 9}};
    vector<int> needs2 = {1, 2, 1};
    cout << "Test Case 2: " << sol.shoppingOffers(price2, special2, needs2) << endl; // 11

    return 0;
}
