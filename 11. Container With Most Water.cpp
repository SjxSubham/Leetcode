#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0, rp = (int)height.size() - 1;
        while (lp < rp) {
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = width * ht;
            maxWater = max(maxWater, currWater);

            // Move the pointer at the shorter line inward
            if (height[lp] < height[rp]) ++lp;
            else --rp;
        }
        return maxWater;
    }
};
