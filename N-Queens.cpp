class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n){

        for(int i=col; i>=0; i--){
            if(board[row][i]=='Q') return false;
        }

        int j=col,i=row;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        
        i=row,j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }

        return true;
    }
    void func(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
          ans.push_back(board);
          return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                func(col+1,board,ans,n);
                board[row][col]='.';
            }
        }

        
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        func(0,board,ans,n);
        return ans.size();
    }
};
