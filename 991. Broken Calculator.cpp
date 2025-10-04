// 991. Broken Calculator

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while(startValue < target){
            if(target & 1){
                ++target;
                ++res;
            }
            target >>= 1;
            ++res;
        }
        return res + startValue - target;
    }
};
