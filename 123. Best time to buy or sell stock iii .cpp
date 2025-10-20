/*
Problem

You are given an array prices where prices[i] is the price of a given stock on day i.

You can complete at most two transactions (a buy and a sell count as one transaction). You cannot hold more than one stock at a time.

Return the maximum profit you can achieve.

Approach

We can use Dynamic Programming with states.

We define four variables to track maximum profit in each state:

firstBuy – Maximum profit after buying the first stock (negative because we spent money).

firstSell – Maximum profit after selling the first stock.

secondBuy – Maximum profit after buying the second stock (taking profit from firstSell into account).

secondSell – Maximum profit after selling the second stock.

We iterate over each price and update these states as we go:

firstBuy   = max(firstBuy, -price)
firstSell  = max(firstSell, firstBuy + price)
secondBuy  = max(secondBuy, firstSell - price)
secondSell = max(secondSell, secondBuy + price)


firstBuy → we want the lowest price for first buy.

firstSell → we want to maximize profit from firstSell.

secondBuy → we “reinvest” profit from firstSell.

secondSell → maximize total profit after second sell.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;

    for(int price : prices){
        firstBuy = max(firstBuy, -price);
        firstSell = max(firstSell, firstBuy + price);
        secondBuy = max(secondBuy, firstSell - price);
        secondSell = max(secondSell, secondBuy + price);
    }

    return secondSell;
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Max Profit: " << maxProfit(prices) << endl;
    return 0;
}
