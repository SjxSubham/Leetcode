#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 1;  
        for (int i = 0; i < nums.size() - maxi; i++) {
            int currLen = 1; 
            int usedBits = nums[i]; 
            for (int j = i + 1; j < nums.size(); j++) {
                if ((usedBits & nums[j]) == 0) {
                    usedBits |= nums[j]; 
                    currLen++;
                }
                else break;
            }
            maxi = max(maxi, currLen);
        }
        return maxi;
    }
};