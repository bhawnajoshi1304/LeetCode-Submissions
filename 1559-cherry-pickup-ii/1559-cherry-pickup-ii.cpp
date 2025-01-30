class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= min(i, n-1); j += 1) {
                for (int k = n - 1; k >= max(n - i - 1, 0); k--) {
                    int ma = -1;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (j + x >= 0 && j + x < n && k + y >= 0 && k + y < n)
                                ma = max(ma, dp[(i + 1)%2][j + x][k + y]);
                        }
                    }
                    if (ma != -1)
                        if (j == k) {
                            dp[i%2][j][k] = ma + grid[i][j];
                        } else {
                            dp[i%2][j][k] = ma + grid[i][j] + grid[i][k];
                        }
                    if (i == m - 1)
                        ans = max(ans, dp[i%2][j][k]);
                }
            }
        }
        return ans;
    }
};