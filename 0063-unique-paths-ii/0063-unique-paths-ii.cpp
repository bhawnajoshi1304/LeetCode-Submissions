class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1-arr[0][0];
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (arr[i][j] != 1) {
                    if (i - 1 >= 0)
                        dp[i][j] += dp[i - 1][j];
                    if (j - 1 >= 0)
                        dp[i][j] += dp[i][j - 1];
                    dp[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};