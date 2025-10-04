// ---------------- Approach ----------------
//
// This is a **cycle detection in a directed graph** problem.
// - Each course is a node.
// - A prerequisite pair [a, b] represents a directed edge b → a.
// - If there is a cycle in this graph, it means courses are interdependent 
//   and cannot all be finished.
//
// We use DFS with two arrays:
// - visited[node]: to mark nodes that have been fully processed.
// - pathVisit[node]: to mark nodes in the current DFS recursion stack.
//
// If during DFS we encounter a node that is already in the current path (pathVisit),
// it means we found a cycle → return false.


// ---------------- Intuition ----------------
//
// - Think of prerequisites as a graph of dependencies.
// - If a cycle exists, some course depends on itself indirectly → impossible to finish.
// - If no cycle exists, we can always complete courses in a valid topological order.


// ---------------- Solution in Code ----------------

class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisit, int node) {
        visited[node] = 1;
        pathVisit[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(adj, visited, pathVisit, neighbor)) {
                    return true; // cycle detected
                }
            }
            else if (pathVisit[neighbor]) {
                return true; // back edge → cycle
            }
        }

        pathVisit[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list from prerequisites
        vector<vector<int>> adj(numCourses);
        for (auto &edge : prerequisites) {
            int a = edge[0], b = edge[1];
            adj[b].push_back(a);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisit(numCourses, 0);

        // Run DFS from each unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, pathVisit, i)) {
                    return false; // cycle found
                }
            }
        }
        return true;
    }
};
