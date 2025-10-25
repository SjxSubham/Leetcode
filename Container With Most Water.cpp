class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; 
        int lp = 0, rp = height.size()-1;
        while(lp<rp){
            int width = rp - lp;
            int ht = min(height[lp],height[rp]);
            int currWater = width*ht;
            maxWater = max(maxWater,currWater);

            height[lp]<height[rp] ? lp++:rp--;
        }
        return maxWater;
    }
};
