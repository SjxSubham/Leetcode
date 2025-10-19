//.........................Binary Search.......................................//
//same as Leetcode 852. find peak Element
 int findPeakElement(vector<int>& nums) {
        // This question is same as leetCode 852.peak index in a mountain array
        int left =0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left+(right-left)/2;
            if(nums[mid] < nums[mid+1]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
