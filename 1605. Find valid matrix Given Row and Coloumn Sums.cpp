class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> vec(m, vector<int>(n,0));
        int i=0;
        int j=0;

        while(i<m && j<n){
            vec[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i]  -= vec[i][j];
            colSum[j] -= vec[i][j];

            if(rowSum[i] == 0){ //T.C - o(n+m)
                                // S.C - O(n*m)
                i++;
            }
            if(colSum[j] == 0){
                j++;
            }
        }

        return vec;
        
    }
};
