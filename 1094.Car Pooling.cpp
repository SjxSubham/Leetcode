class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> pickups;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> drops;
        pickups.reserve(trips.size());
        for (auto &t : trips){
            pickups.emplace_back(t[1], t[0]);
            drops.push({t[2], t[0]});
        }
        sort(pickups.begin(), pickups.end());
        int i = 0, curr = 0;
        while (!drops.empty()){
            int nextDrop = drops.top().first;
            while (i < (int)pickups.size() && pickups[i].first < nextDrop){
                curr += pickups[i].second;
                if (curr > capacity) return false;
                ++i;
            }
            curr -= drops.top().second;
            drops.pop();
        }
        while (i < (int)pickups.size()){
            curr += pickups[i].second;
            if (curr > capacity) return false;
            ++i;
        }
        return true;
    }
};
