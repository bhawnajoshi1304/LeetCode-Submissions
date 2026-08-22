class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        if (board[i][j] == 'O') {
            board[i][j] = '*';
            vector<int> dx = {0, -1, 1, 0}, dy = {-1, 0, 0, 1};
            for (int ii = 0; ii < 4; ii += 1) {
                if (isValid(i + dx[ii], j + dy[ii], n, m))
                    dfs(board, i + dx[ii], j + dy[ii], n, m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i += 1) {
            dfs(board, i, 0, n, m);
            dfs(board, i, m - 1, n, m);
        }
        for (int i = 1; i < m - 1; i += 1) {
            dfs(board, 0, i, n, m);
            dfs(board, n - 1, i, n, m);
        }
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};