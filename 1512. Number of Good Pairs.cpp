// T.C - O(N)
// S.C - O(N)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans =0;
        unordered_map<int, int>count;
        for(int i: nums){
            ans += count[i]++;
        }
        return ans;
    }
};
