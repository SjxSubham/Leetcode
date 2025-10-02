class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        res.reserve(n * m);
        for (int d = 0; d < n + m - 1; d++) {
            vector<int> tmp;
            int r = d < m ? 0 : d - m + 1;
            int c = d < m ? d : m - 1;
            while (r < n && c >= 0) {
                tmp.push_back(mat[r][c]);
                r++;
                c--;
            }
            if (d % 2 == 0) reverse(tmp.begin(), tmp.end());
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};
