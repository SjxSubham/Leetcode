class Solution {
public:
    vector<int> rearrangeFruits(vector<int>& fruits) {
       
        unordered_map<int, int> freq;
        for (int fruit : fruits) freq[fruit]++;
        
    
        priority_queue<pair<int,int>> pq;
        for (auto &p : freq) pq.push({p.second, p.first});
        
        vector<int> result;
        pair<int,int> prev = {-1, -1}; // last placed fruit
        
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            result.push_back(cur.second);
            cur.first--;
            
            if (prev.first > 0) pq.push(prev);
            prev = cur;
        }
        
        return result;
    }
};

