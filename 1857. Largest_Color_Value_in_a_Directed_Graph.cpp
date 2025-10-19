// Use Topological Sorting (Kahn’s Algorithm) + Dynamic Programming.

// For each node, maintain a count[node][color] array of size 26.

// When processing a node, propagate color counts to its neighbors.

// Keep track of max color count during traversal.

// If all nodes are processed → return max count; else → cycle → -1.


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        
        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        
        queue<int> q;
        for (int i=0;i<n;i++)
            if (indegree[i]==0)
                q.push(i);

        vector<vector<int>> count(n,vector<int>(26, 0)); 
        int vis=0;
        int ans=0;

        while (!q.empty()) {
            int u=q.front();
            q.pop();
            vis++;


            int colorIdx=colors[u]-'a';
            count[u][colorIdx]++;
            ans=max(ans,count[u][colorIdx]);

            for(int v:graph[u]) {
                for(int c=0;c<26;c++)
                    count[v][c] = max(count[v][c],count[u][c]);
                if(--indegree[v]==0)
                    q.push(v);
            }
        }

        return (vis==n)?ans:-1;
    }
};
