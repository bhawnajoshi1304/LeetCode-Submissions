class Solution {
public:
    void nQueens(int n, vector<string>& board, vector<vector<string>>& ans, int col, vector<int>& mp, vector<int>& diagonal1, vector<int>& diagonal2) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row += 1) {
            if (mp[row] == 0 && diagonal1[row + col] == 0 &&
                diagonal2[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                mp[row] = 1;
                diagonal1[row + col] = 1;
                diagonal2[n - 1 + col - row] = 1;
                nQueens(n, board, ans, col + 1, mp, diagonal1, diagonal2);
                board[row][col] = '.';
                mp[row] = 0;
                diagonal1[row + col] = 0;
                diagonal2[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> s(n, string(n, '.'));
        vector<int> row(n), diagonal1(2 * n - 1), diagonal2(2 * n - 1);
        nQueens(n, s, ans, 0, row, diagonal1, diagonal2);
        return ans;
    }
};