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
