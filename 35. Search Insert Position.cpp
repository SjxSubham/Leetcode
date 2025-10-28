/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
  Binary search Algorithm
*/
int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1; //length is used to extarct the amx size of array
        while(left <= right){
            int mid = left +(right - left)/2;
            if( nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};
