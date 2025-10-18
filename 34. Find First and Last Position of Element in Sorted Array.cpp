/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
vector<int> searchRange(vector<int>&nums , int target){
//most optimised solution
        //Two pointer approach
        int left =0;
        int right = nums.size()-1;
        while(left <= right){
            if(nums[left] < target){
                left++;
            }
            else if(nums[right] > target){
                right--;
            }
            else if(nums[left] == nums[right]){
                return {left,right};
            }
        }

        return {-1,-1};
}
