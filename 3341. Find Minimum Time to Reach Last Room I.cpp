#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node {
    int r, c;
    ll t;
};
struct Cmp {
    bool operator()(const Node &a, const Node &b) const {
        return a.t > b.t;
    }
};
ll minTimeToReach(vector<vector<ll>>& moveTime) {
    int n = moveTime.size();
    int m = moveTime[0].size();
    const ll INF = LLONG_MAX / 4;
    vector<vector<ll>> dist(n, vector<ll>(m, INF));
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
            ll arrival = max(moveTime[nr][nc], cur.t) + 1;
            if (arrival < dist[nr][nc]) {
                dist[nr][nc] = arrival;
                pq.push({nr, nc, arrival});
            }
        }
    }
    return dist[n - 1][m - 1];
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> moveTime(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> moveTime[i][j];
        }
    }
    ll res = minTimeToReach(moveTime);
    cout << res << "\n";
    return 0;
}
