// LeetCode Problem #121: Best Time to Buy and Sell Stock
// Difficulty: Easy
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
Problem Description:
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing 
a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve 
any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
- 1 <= prices.length <= 10^5
- 0 <= prices[i] <= 10^4
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Finds the maximum profit from buying and selling stock once.
     * 
     * Algorithm:
     * - Track the minimum price seen so far
     * - For each price, calculate profit if we sell at that price
     * - Keep track of maximum profit
     * 
     * @param prices Vector of stock prices
     * @return Maximum profit possible
     * 
     * Time Complexity: O(n) - Single pass through the array
     * Space Complexity: O(1) - Only using two variables
     */
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int minPrice = prices[0];  // Minimum price seen so far
        int maxProfit = 0;         // Maximum profit found
        
        for (int i = 1; i < prices.size(); i++) {
            // Update minimum price if current price is lower
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate profit if we sell at current price
            else {
                int profit = prices[i] - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }
        
        return maxProfit;
    }
};

// Helper function to print results
void printResult(vector<int>& prices, int expected) {
    Solution sol;
    int result = sol.maxProfit(prices);
    
    cout << "Prices: [";
    for (int i = 0; i < prices.size(); i++) {
        cout << prices[i];
        if (i < prices.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    cout << "Max Profit: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << "Status: " << (result == expected ? "PASS ✓" : "FAIL ✗") << endl;
    cout << "-------------------" << endl;
}

int main() {
    cout << "LeetCode #121: Best Time to Buy and Sell Stock" << endl;
    cout << "===============================================" << endl << endl;
    
    // Test Case 1: Normal case with profit
    vector<int> test1 = {7, 1, 5, 3, 6, 4};
    printResult(test1, 5);
    
    // Test Case 2: Decreasing prices (no profit)
    vector<int> test2 = {7, 6, 4, 3, 1};
    printResult(test2, 0);
    
    // Test Case 3: Single price
    vector<int> test3 = {5};
    printResult(test3, 0);
    
    // Test Case 4: Two prices with profit
    vector<int> test4 = {1, 2};
    printResult(test4, 1);
    
    // Test Case 5: All same prices
    vector<int> test5 = {3, 3, 3, 3};
    printResult(test5, 0);
    
    // Test Case 6: Buy at first, sell at last
    vector<int> test6 = {1, 2, 3, 4, 5};
    printResult(test6, 4);
    
    return 0;
}

/*
Expected Output:
=================================================
LeetCode #121: Best Time to Buy and Sell Stock
===============================================

Prices: [7,1,5,3,6,4]
Max Profit: 5
Expected: 5
Status: PASS ✓
-------------------
Prices: [7,6,4,3,1]
Max Profit: 0
Expected: 0
Status: PASS ✓
-------------------
Prices: [5]
Max Profit: 0
Expected: 0
Status: PASS ✓
-------------------
Prices: [1,2]
Max Profit: 1
Expected: 1
Status: PASS ✓
-------------------
Prices: [3,3,3,3]
Max Profit: 0
Expected: 0
Status: PASS ✓
-------------------
Prices: [1,2,3,4,5]
Max Profit: 4
Expected: 4
Status: PASS ✓
-------------------

Time Complexity: O(n) where n is the number of prices
Space Complexity: O(1) - constant extra space

Algorithm Explanation:
1. Keep track of the minimum price encountered so far
2. For each price, calculate the profit if we sold at that price
3. Update the maximum profit if current profit is higher
4. This works because we need to buy before we sell, so we only
   consider selling after we've seen the minimum buy price
*/
