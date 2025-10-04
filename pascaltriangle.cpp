class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> ansRow;
        long long sum=1;
        ansRow.push_back(sum);
        for(int col=1;col<row;col++){
            sum=sum*(row-col);
            sum=sum/col;
            ansRow.push_back(sum);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
    return ans;
    }
};