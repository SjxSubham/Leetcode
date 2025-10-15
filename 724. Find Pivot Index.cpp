//it can also be done by Binary Search...
constraints - 10^4

  T.C - O(n)
  S.C = O(n)

int prefixSumApproach(vector<int>& nums) {
        vector<int>lsum(nums.size(),0);
        vector<int>rsum(nums.size(),0);
        for(int i=1; i<nums.size();i++){
            lsum[i] = lsum[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2; i>=0; i--){
            rsum[i] = rsum[i+1] +nums[i+1];
        }
        for(int i=0; i<nums.size();i++){
            if(lsum[i] == rsum[i]){
                return i;
            }
        }
        return-1;
    }
    int pivotIndex(vector<int>& nums){
        return prefixSumApproach(nums);
    }
