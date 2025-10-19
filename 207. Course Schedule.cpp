class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            inDegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        int processed = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;
            for (int v : graph[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return processed == numCourses;
    }
};