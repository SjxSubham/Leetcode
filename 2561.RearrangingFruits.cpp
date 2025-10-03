// *********** APPROACH *************

// Analyze the input (probably a list or string representing fruits).
// Determine the goal: rearranging fruits to satisfy a condition (like sorting, grouping, or alternating types).
// Identify constraints: minimize swaps, moves, or cost if mentioned.
// Use an efficient method to achieve the arrangement: could be greedy, two-pointers, counting/frequency array, or sorting.


// *********** INTUITOIN *************

// If we have counts of each fruit, we can decide the optimal arrangement based on frequency or positioning rules.
// The problem is likely solved by iteratively placing fruits in the desired order while keeping track of remaining counts.
// Special cases to consider: all same type, two types only, or odd/even total fruits.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeFruits(vector<int>& fruits) {
       
        unordered_map<int, int> freq;
        for (int fruit : fruits) freq[fruit]++;
        
    
        priority_queue<pair<int,int>> pq;
        for (auto &p : freq) pq.push({p.second, p.first});
        
        vector<int> result;
        pair<int,int> prev = {-1, -1}; // last placed fruit
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            result.push_back(cur.second);
            cur.first--;
            
            if (prev.first > 0) pq.push(prev);
            prev = cur;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {1,1,2,2,3,3}; // sample input
    vector<int> rearranged = sol.rearrangeFruits(fruits);

    for (int f : rearranged) cout << f << " ";
    cout << endl;
    return 0;
}
