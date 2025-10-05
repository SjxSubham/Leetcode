class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;

        int dir[5] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [curr, pos] = pq.top(); pq.pop();
            int row = pos.first, col = pos.second;

            if (row == m - 1 && col == n - 1)
                return curr;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i], ncol = col + dir[i + 1];
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
                    int nextTime = max(curr, moveTime[nrow][ncol]) + 1;
                    if (nextTime < dis[nrow][ncol]) {
                        dis[nrow][ncol] = nextTime;
                        pq.push({nextTime, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};
