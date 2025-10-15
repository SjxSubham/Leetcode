//................................
 int countHillValley(vector<int>& nums) {
        int ans = 0;
        int left = nums[0];

        for(int i=1; i<nums.size()-1 ;i++)
            if(left < nums[i] && nums[i] > nums[i+1] || //Hill
                left > nums[i] && nums[i] < nums[i+1]){ //valeys
                    ans++;
                    left = nums[i];
                }
        return ans;
    }
