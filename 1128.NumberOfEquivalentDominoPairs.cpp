class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int res = 0;
        
        for (auto &d : dominoes) {
            int a = d[0], b = d[1];
            int key = min(a, b) * 10 + max(a, b);
            
            res += count[key];
            count[key]++;
        }
        
        return res;
    }
};
