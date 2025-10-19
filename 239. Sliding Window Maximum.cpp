//Queue class 3
//Hard C++ solution...
//Using STL Deque & Vector

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        //first window of k size
        for(int i=0;i<k;i++){
            //chote element remove kardo
            while(!dq.empty() && nums[i] >= nums[dq.back()] ){
                dq.pop_back();
            }
            //inserting index, so that we can checkout of window element
            dq.push_back(i);
        }
        //store ans for first window
        ans.push_back(nums[dq.front()]); // array ki value ko store akr rhe hai

        // remaining windows ko track krengey
        for(int i=k;i<nums.size();i++){
            //out of window element ko remove kardia
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }

            //ab firse current elemnt k liye ,chote element ko remove krana hai
             while(!dq.empty() && nums[i] >= nums[dq.back()] ){
                dq.pop_back();
            }
            //inserting index, so that we can checkout of window element
            dq.push_back(i);

            //current window ka ans store karana hai
            ans.push_back(nums[dq.front()]);

        }
        return ans;
        }
};
