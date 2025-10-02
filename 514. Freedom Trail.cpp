class Solution {
public:
    int n;
    string ring,key;
    vector<vector<int>> memo;
    array<vector<int>,26> pos;

    int dfs(int cur,int kidx) {
        if (kidx==(int)key.size()) return 0;
        int &res=memo[cur][kidx];
        if (res != -1) return res;
        res=INT_MAX/4;
        int ch=key[kidx]-'a';
        for (int p : pos[ch]) {
            int diff=abs(cur-p);
            int dist=min(diff,n-diff);
            int sub=dfs(p,kidx+1);
            res=min(res,dist+1+sub);
        }
        return res;
    }

    int findRotateSteps(string ring_,string key_) {
        ring=ring_;
        key=key_;
        n=ring.size();
        memo.assign(n,vector<int>(key.size(),-1));
        for (int i=0; i<26; ++i) pos[i].clear();
        for (int i=0; i<n; ++i) pos[ring[i]-'a'].push_back(i);
        return dfs(0,0);
    }
};