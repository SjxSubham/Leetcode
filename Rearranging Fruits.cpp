✅ Approach -> Step 1: Count Frequencies and Find Global Minimum

    Initialize a map, balance, to store the net frequency of each fruit cost.

    Initialize min_val to track the lowest cost fruit overall (across both baskets).

    Iterate through basket1: increment balance[fruit] and update min_val.

    Iterate through basket2: decrement balance[fruit] and update min_val.

Step 2: Feasibility Check and Collect Transfers

    Initialize a list, transfers, to store the values of fruits that are in surplus and need to be moved.

    Iterate through the balance map:

        Feasibility: If the absolute balance of any fruit, ∣balance[val]∣, is odd, return -1.

        Collection: If the balance is non-zero, this means there is an imbalance. The number of fruits that need to be moved is 2∣balance[val]∣​.

        Add the fruit cost val to the transfers list 2∣balance[val]∣​ times. (We only care about the fruit value, not which basket it came from, as long as it's the one in surplus).

Step 3: Calculate Minimum Cost (Greedy)

    Sort the transfers list in ascending order. This ensures we prioritize minimizing the cost by considering the cheapest fruits first.

    Initialize a total cost variable, total_cost, to 0.

    The total number of swaps required is 2∣transfers∣​. Iterate from i=0 up to i<2∣transfers∣​.

    For each fruit val=transfers[i]:

        Calculate the direct swap cost: val (since we've sorted and are taking the cheaper half, this fruit is the one determining the cost of its swap pair).

        Calculate the indirect swap cost: 2×min_val.

        Add the minimum of the two costs to the total:
        total_cost+=min(val,2×min_val)

    Return total_cost.

This final step correctly applies the greedy strategy by ensuring the movement of the cheapest surplus fruits is paid for optimally, either by a direct swap (cost val) or the "middleman" swap (cost 2×min_val).

✅ Intution -> Greedy Swapping Strategy

The problem boils down to equalizing the multiset of fruits in both baskets with minimum cost.

1. The Total Balance Must Be Even
For the two baskets to be made exactly equal, the total number of fruits of any given cost across both baskets must be an even number. This is because the final, equal baskets must each contain half of that total count. If the total count is odd, it's impossible to divide them equally, so we immediately return -1.

2. Identifying the Imbalance
Once we confirm feasibility, we use a frequency map to track the imbalance. A fruit is "imbalanced" if one basket has more of it than the final, balanced basket should. For every imbalanced fruit type, we only need to move half of the total imbalance (which is the amount of surplus in one basket) to the other basket.

3. The Two Swap Options (Greedy Choice)
We have a list of all the surplus fruits (transfers) that need to be swapped out of their current basket. To minimize total cost, we employ a greedy strategy by considering the two ways a fruit val can be moved:

    Option 1: Direct Swap (Cost = val)
        Swap the surplus fruit val with a deficit fruit val′ from the other basket. The cost is min(val,val′).
        By always pairing the cheapest remaining surplus fruit with the most expensive remaining surplus fruit (which becomes the deficit fruit in the other basket), we ensure that val is the minimum cost for this pairing.

    Option 2: Indirect Swap (Cost = 2×min_val)
        Swap the surplus fruit val with the globally cheapest fruit (min_val). Cost: min_val.
        Then, swap the min_val fruit back to the other basket. Cost: min_val.
        Total Cost: 2×min_val.

        This is useful when the fruit val is very expensive, making 2×min_val cheaper than a direct swap.
✅ Code -> 
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       long long total_cost = 0;
        map<int, int> balance;
        int min_val = INT_MAX;
        for (int fruit : basket1) {
            balance[fruit]++;
            min_val = min(min_val, fruit);
        }
        for (int fruit : basket2) {
            balance[fruit]--;
            min_val = min(min_val, fruit);
        }

        vector<int> transfers; 
        
        for (auto const& [val, bal] : balance) {
           
            if (bal % 2 != 0) {
                return -1;
            }

            
            if (bal > 0) {
                
                for (int i = 0; i < bal / 2; ++i) {
                    transfers.push_back(val);
                }
            } else if (bal < 0) {
                
                for (int i = 0; i < abs(bal) / 2; ++i) {
                    transfers.push_back(val);
                }
            }
        }

       
        sort(transfers.begin(), transfers.end());
        
       
        int m = transfers.size();
        for (int i = 0; i < m / 2; ++i) {
            long long val = transfers[i];
            
           
            total_cost += min(val, 2LL * min_val);
        }

        return total_cost; 
    }
};

✅ Code Link -> https://leetcode.com/problems/rearranging-fruits/
