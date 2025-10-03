/*
 * Koko Eating Bananas (Binary Search on Answer)
 *
 * Description:
 * We are given piles of bananas and hours h. Koko eats at a fixed speed k bananas per hour.
 * We need to find the minimum k such that Koko can finish all bananas in h hours.
 *
 * Approach:
 * - Use binary search on answer (k).
 * - Lower bound = 1 (minimum speed), upper bound = max(piles).
 * - Check function: Given a speed k, can Koko finish all bananas within h hours?
 *   -> Compute total hours = sum( ceil(pile/k) ) for all piles.
 *   -> If total hours <= h, it's possible.
 * - Binary search for the smallest valid k.
 *
 * Time Complexity: O(n log(max(piles))), where n = number of piles
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (int bananas : piles) {
            totalHours += (bananas + k - 1) / k; // ceil(bananas/k)
            if (totalHours > h) return false;
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEat(piles, h, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> piles1 = {3,6,7,11};
    int h1 = 8;
    cout << "Test Case 1: " << sol.minEatingSpeed(piles1, h1) << endl; // 4

    // Test Case 2
    vector<int> piles2 = {30,11,23,4,20};
    int h2 = 5;
    cout << "Test Case 2: " << sol.minEatingSpeed(piles2, h2) << endl; // 30

    // Test Case 3
    vector<int> piles3 = {30,11,23,4,20};
    int h3 = 6;
    cout << "Test Case 3: " << sol.minEatingSpeed(piles3, h3) << endl; // 23

    return 0;
}
