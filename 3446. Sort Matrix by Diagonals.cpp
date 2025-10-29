class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        vector<int> t;
        int cnt = 1;
        int j=0;
        for(int i=grid.size()-1;i>=0;i--){
            int p=i;
            while(j < grid.size() && p < grid.size()){
                t.push_back(grid[p][j]);
                p++;
                j++;
            }
            sort(t.begin(), t.end());
            reverse(t.begin(), t.end());
            ans.push_back(t);
            t.clear();
            j=0;
        }
        vector<vector<int>> a1;
        int r = 1;
        for(int k=1;k<grid.size();k++){
            int q = 0;
            int d = r;
            while(q < grid.size() && d < grid.size()){
                t.push_back(grid[q][d]);
                q++;
                d++;
            }
            sort(t.begin(), t.end());
            a1.push_back(t);
            t.clear();
            r++;
        }
        for(int i=0;i<a1.size();i++){
            ans.push_back(a1[i]);
        }
        j = grid.size()-1;
        int p = 0,q=0;
        for(int i=grid.size()-1;i>=0;i--){
            int r = i;
            while(q < ans[p].size()){
                grid[r][j] = ans[p][q];
                q++;
                r++;
                j++;
            } 
            j=0;
            q=0;
            p++;
        }
        q=0;
        j=1;
        r=0;
        for(int i=1;i<grid.size();i++){
            while(q < ans[p].size()){
                grid[r][j] = ans[p][q];
                q++;
                r++;
                j++;
            }
            j=i+1;
            r=0;
            q=0;
            p++;
        }
        return grid;
    }
};
