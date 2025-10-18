class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int Mask=1<<n;
        vector<vector<int>> powerSet(Mask);
        for (int m=0; m<Mask; m++){
            for(int i=0; i<n; i++){
                if (m& 1<<i)
                    powerSet[m].push_back(nums[i]);
            }
        }
        return powerSet;
    }
};
