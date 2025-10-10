// 🧠 Approach

// This problem can be modeled as a Directed Graph Cycle Detection problem.
// Each course is represented as a node, and a directed edge b → a means you must take course b before course a.

// To determine if all courses can be finished, we must ensure no cycle exists in this graph.
// We use Kahn’s Algorithm (Topological Sorting using BFS) to detect cycles.

// 🚀 Algorithm Steps

// Build the Graph:

// - Create an adjacency list adj where adj[b] contains all courses that depend on b.
// - Maintain an array inDeg to store the number of prerequisites (incoming edges) for each course.

// Find Starting Nodes:

// - Push all nodes with inDeg[i] == 0 (no prerequisites) into a queue — these can be taken first.
// - Topological Sorting using BFS:
// - While the queue isn’t empty:
// - Pop a node x (a course that can be completed now).
// - Increment a counter c for completed courses.
// - For each neighbor adj[x][i], reduce its inDeg by 1 (as its prerequisite x is now done).
// - If any neighbor’s inDeg becomes 0, push it into the queue.

// Check Completion:

// - If all courses are processed (c == V), return true.
// - Otherwise, there’s a cycle → some courses depend on each other, so return false.


// Solution in CPP:

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        vector<int> inDeg(V);
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            inDeg[a]++;
        }
        vector<int> vis(V);
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (inDeg[i] == 0)
                q.push(i);
        }
        int c = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            c++;

            for (int i = 0; i < adj[x].size(); i++) {
                inDeg[adj[x][i]]--;
                if (inDeg[adj[x][i]] == 0)
                    q.push(adj[x][i]);
            }
        }
        return c == V;
    }
};