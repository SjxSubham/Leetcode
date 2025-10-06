class Solution {
public:
     vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int prevCellVal, vector<vector<bool>>& visited) {
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) { //invalid cell
            return;
        }

        if(heights[i][j] < prevCellVal || visited[i][j])
            return;

        visited[i][j] = true;
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); //rows
        int n = heights[0].size(); //cols

        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false)); //pacificVisited[i][j] = true, means [i][j] water can go to Pacific //m*n
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false)); //atlanticVisited[i][j] = true, means [i][j] water can go to atlantic //m*n
        //T.C : O(m*n)
        //S.C : O(m*n)


        //Top Row and Bottom Row
        //Top Row : Pacific connected already
        //Bottom Row : atlantic connected already

        for(int j = 0; j < n; j++) {
            DFS(heights, 0, j, INT_MIN, pacificVisited); //Top Row
            DFS(heights, m-1, j, INT_MIN, atlanticVisited); //Top Row
        }

        //First col and last column
        //First col : Pacific connected already
        //Last col : atlantic connected already
        for(int i = 0; i < m; i++) {
            DFS(heights, i, 0, INT_MIN, pacificVisited); //First column
            DFS(heights, i, n-1, INT_MIN, atlanticVisited); //Last Column
        }


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result; 
    }
};
