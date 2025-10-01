class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;  
        int emptyBottles = numBottles;          
      
        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;  
            totalDrunk += newBottles; 
            emptyBottles = emptyBottles % numExchange + newBottles;  
        }
        
        return totalDrunk;
    }
};

/* 
Alternative Mathematical Solution (More Efficient):
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Mathematical formula: numBottles + (numBottles - 1) / (numExchange - 1)
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

Problem Explanation:
- You have numBottles full water bottles
- After drinking, you get numBottles empty bottles
- You can exchange numExchange empty bottles for 1 new full bottle
- Find maximum bottles you can drink

Example: numBottles = 9, numExchange = 3
- Drink 9 bottles → 9 empty bottles
- Exchange 9 empty → 3 new bottles, 0 empty remaining
- Drink 3 bottles → 3 empty bottles  
- Exchange 3 empty → 1 new bottle, 0 empty remaining
- Drink 1 bottle → 1 empty bottle
- Cannot exchange anymore (need 3 empty for 1 new)
- Total drunk: 9 + 3 + 1 = 13

Time Complexity: O(log(numBottles)) - simulation approach
                 O(1) - mathematical approach
Space Complexity: O(1)
*/