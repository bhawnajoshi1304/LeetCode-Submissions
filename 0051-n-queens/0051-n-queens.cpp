class Solution {
public:
    bool canPlace(int row,int col,vector<string> &board, int n){
        // check row, col, diagonal for queen
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q') return false;
            i-=1;
            j-=1;
        }
        i=row;
        j=col;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        i=row;
        while(i>=0){
            if(board[i][col] == 'Q') return false;
            i-=1;
        }
        j=col;
        while(j>=0){
            if(board[row][j] == 'Q') return false;
            j-=1;
        }
        return true;
    }
    void nQueens(int n, vector<string> &board, vector<vector<string>> &ans, int col=0){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row+=1){
            if(canPlace(row,col,board,n)){
                board[row][col]='Q';
                nQueens(n,board,ans,col+1);
                board[row][col]='.';   
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> s(n,string(n,'.'));
        nQueens(n,s,ans);
        return ans;
    }
};