class Solution {
public:
    struct Node {
        int r, c, t;
    };

    struct Cmp {
        bool operator()(const Node &a, const Node &b) const {
            return a.t > b.t;
        }
    };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        const int INF = INT_MAX / 2;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        priority_queue<Node, vector<Node>, Cmp> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            if (cur.t > dist[cur.r][cur.c]) continue;
            if (cur.r == n - 1 && cur.c == m - 1) return cur.t;

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int arrival = max(moveTime[nr][nc], cur.t) + 1;
                if (arrival < dist[nr][nc]) {
                    dist[nr][nc] = arrival;
                    pq.push({nr, nc, arrival});
                }
            }
        }

        return -1;
    }
};
