class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        int temp = INT_MIN;
        for(int i: nums){
            if(i>0) s.insert(i);
            else{
                temp = max(temp,i);
            }
        }
        return s.empty()?temp:accumulate(s.begin(), s.end(), 0);
    }
};