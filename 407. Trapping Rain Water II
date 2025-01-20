class Solution {
public:
       typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> boundaryCells;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r) {
            for (int c : {0, n - 1}) { //0 : left most boundary, cols-1 right most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        for (int c = 0; c < n; ++c) {
            for (int r : {0, m - 1}) { //0 : top most boundary, rows-1 bottom most boundary
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        }

        int water = 0;

        while(!boundaryCells.empty()){
            PP p = boundaryCells.top();
            boundaryCells.pop();

            int heigth = p.first;
            int i = p.second.first;
            int j = p.second.second;

            //find neighbourss
            for(vector<int>& dir: directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ <m && j_ >= 0 && j_ <n && !visited[i_][j_]){
                    water += max(heigth -  heightMap[i_][j_], 0);
                    boundaryCells.push({max(heigth, heightMap[i_][j_]), {i_, j_}});

                    visited[i_][j_] = true;

                }
            }
        }
        return water;
    }
};
