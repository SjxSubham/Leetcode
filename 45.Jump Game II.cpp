class Solution {
public:
    int jump(vector<int>& nums) {
        int right = 0, left = 0, steps = 0;
        while(right<nums.size()-1){
            int maxDist = 0;
            for(int i=left;i<=right;i++){
                maxDist = std::max(maxDist,nums[i]+i);
            }
            left = right+1;
            right = maxDist;
            steps++;
        }
        return steps;
    }
};
