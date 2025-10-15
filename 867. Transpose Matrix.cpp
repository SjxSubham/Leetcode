//Followup qs. for interview

### What if the input is always a square matrix?
#### Code- 
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      swap(matrix[i][j],matrix[j][i]);
    }
  }

public:

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> result(n, vector<int>(m));       //n x m - T.c  S.C - O(1)

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                 result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};
