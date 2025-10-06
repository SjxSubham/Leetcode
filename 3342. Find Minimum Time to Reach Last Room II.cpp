//
// Created by SaraNabih on 10/6/2025.
//
#include <bits/stdc++.h>
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        using T = tuple<int,int,int>; // time, x, y
        priority_queue<T, vector<T>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (x == n-1 && y == m-1) return t;
            if (t > dist[x][y]) continue;

            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int nt = t + 1;
                if (nt < moveTime[nx][ny]) {
                    int diff = moveTime[nx][ny] - nt;
                    if (diff % 2 == 1) nt = moveTime[nx][ny] + 1;
                    else nt = moveTime[nx][ny];
                }

                if (nt < dist[nx][ny]) {
                    dist[nx][ny] = nt;
                    pq.push({nt, nx, ny});
                }
            }
        }

        return -1;
    }
};
