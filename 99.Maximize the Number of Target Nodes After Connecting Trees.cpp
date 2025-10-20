class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // Build adjacency lists
        auto graph2 = buildGraph(edges2);
        auto graph1 = buildGraph(edges1);
        int tree2Size = edges2.size() + 1;
        int tree1Size = edges1.size() + 1;

        // Step 1: Find maximum nodes reachable within distance (k - 1) in tree2
        int maxNodesInTree2 = 0;
        for (int node = 0; node < tree2Size; ++node) {
            maxNodesInTree2 = max(maxNodesInTree2, countReachableNodes(graph2, node, -1, k - 1));
        }

        // Step 2: For each node in tree1, count reachable nodes within distance k
        vector<int> result(tree1Size);
        for (int node = 0; node < tree1Size; ++node) {
            int reachable = countReachableNodes(graph1, node, -1, k);
            result[node] = reachable + maxNodesInTree2;
        }

        return result;
    }

private:
    // Builds adjacency list for given edges
    vector<vector<int>> buildGraph(const vector<vector<int>>& edges) {
        int nodeCount = edges.size() + 1;
        vector<vector<int>> adj(nodeCount);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    // Counts number of nodes within remainingDistance using DFS
    int countReachableNodes(const vector<vector<int>>& graph, int node, int parent, int remainingDistance) {
        if (remainingDistance < 0) return 0;

        int count = 1; // count current node
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                count += countReachableNodes(graph, neighbor, node, remainingDistance - 1);
            }
        }
        return count;
    }
};
