class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<int>>> dp(2*n-1, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][0] = grid[0][0];

        for (int k = 1; k < 2 * n - 1; ++k) {
            for (int x1 = max(0, k - n + 1); x1 <= min(n - 1, k); ++x1) {
                for (int x2 = max(0, k - n + 1); x2 <= min(n - 1, k); ++x2) {
                    int y1 = k - x1, y2 = k - x2;
                    if (y1 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1)
                        continue;

                    int cherries = grid[x1][y1];
                    if (x1 != x2 || y1 != y2)
                        cherries += grid[x2][y2];

                    int best = -1;

                    for (int dx1 : {-1, 0}) {
                        for (int dx2 : {-1, 0}) {
                            int px1 = x1 + dx1, px2 = x2 + dx2;
                            int py1 = k - 1 - px1, py2 = k - 1 - px2;

                            if (px1 >= 0 && px2 >= 0 && py1 >= 0 && py1 < n && py2 >= 0 && py2 < n && dp[k - 1][px1][px2] != -1) {
                                best = max(best, dp[k - 1][px1][px2]);
                            }
                        }
                    }

                    if (best != -1)
                        dp[k][x1][x2] = best + cherries;
                }
            }
        }

        return max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};
