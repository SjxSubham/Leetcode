/*
Intuition:
We can simulate the process: drink all current bottles → they become empty.
If we have enough empty bottles, exchange them for one new full bottle, drink it, and repeat.
Since the exchange cost increases each time, eventually we won’t be able to exchange anymore.

Approach:
- Start with numBottles as the initial drunk count and empty bottles.
- While empty bottles ≥ numExchange:
    * Exchange numExchange empties for 1 full bottle.
    * Drink it (increase drunk count).
    * Update empty bottles (-numExchange + 1).
    * Increment numExchange (cost increases).
- Return the total drunk bottles.
*/


class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottleDrunk = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            numExchange++;
            bottleDrunk++;
            emptyBottles++;
        }
        return bottleDrunk;
    }
};