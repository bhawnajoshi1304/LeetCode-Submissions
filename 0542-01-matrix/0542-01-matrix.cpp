class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1)); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }
        int dy[4] = {0, -1, 1, 0}, dx[4] = {-1, 0, 0, 1};
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int x = q.front().second;
            q.pop();
            
            for (int ii = 0; ii < 4; ii++) {
                int newRow = i + dx[ii];
                int newCol = j + dy[ii];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && ans[newRow][newCol] == -1) {
                    q.push({{newRow, newCol}, x + 1});
                    ans[newRow][newCol] = x + 1;  
                }
            }
        }
        return ans;
    }
};
