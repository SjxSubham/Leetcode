class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ltr = 1, rtl = 1;
        for(int i=0; i<n; i++){
            if(ltr == 0){
                ltr = 1;
            }
            if(rtl == 0){
                rtl = 1;
            }

            ltr *= nums[i];
            int j = n-i-1;
            rtl *= nums[j];

            maxi = max({ltr,rtl,maxi});
        }
        return maxi;
    }
};
