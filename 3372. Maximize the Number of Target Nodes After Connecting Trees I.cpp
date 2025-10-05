class Solution {
public: 
    int n, m;
    inline void build_adj(const vector<vector<int>>& edges, vector<vector<int>>& adj){
        for (const auto& e: edges){
            const int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int dfs(int i, int parent,  int maxLen, const vector<vector<int>>& adj){
        if (maxLen<0) return 0;
        int cnt=1;
        for(int j:adj[i]){
            if (j==parent) continue;
            cnt+=dfs(j, i, maxLen-1, adj);
        }
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        n=edges1.size()+1, m=edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);
        build_adj(edges1, adj1);
        build_adj(edges2, adj2);
        int cnt2=0;
        for(int i=0; i<m; i++)
            cnt2=max(cnt2, dfs(i, -1, k-1, adj2));
        vector<int> ans(n);
        for(int i=0; i<n; i++)
            ans[i]=dfs(i, -1, k, adj1)+cnt2;
        return ans;

    }
};
