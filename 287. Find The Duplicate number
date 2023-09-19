// T.C - O(n)
// by using only xtra constant space

int findDuplicate(vector<int>& nums) {
       int ans =0;
       //sort it
       sort(nums.begin(),nums.end());
       for(int i=0; i<nums.size()-1; i++){
           //if  two consecutive elements are equal
           //you have find a duplicate
           //break the loop
           if(nums[i]== nums[i+1]){
               ans = nums[i];
               break;
           }   
       }   
    //return the duplicate value
     return ans;  
    }
