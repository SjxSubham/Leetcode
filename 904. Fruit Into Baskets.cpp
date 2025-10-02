class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits=0;
        unordered_map<int,int>res;
        int left=0;
        for(int right=0;right<fruits.size();right++){
            res[fruits[right]]++;
                while(res.size()>2){
                    res[fruits[left]]--;

                    if(res[fruits[left]]==0) res.erase(fruits[left]);
                    left++;
                }
                maxFruits=max(maxFruits,right-left+1);

        }
        return maxFruits;
    }
};