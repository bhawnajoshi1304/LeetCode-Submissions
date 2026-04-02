class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                for (int k = 0; k < 3; k += 1) {
                    if (i == 0 && j == 0)
                        if(k==0)
                        dp[i][j][k] = coins[i][j];
                        else if(k==1 && coins[i][j]<0)
                        dp[i][j][k]=0;
                        else
                        dp[i][j][k]=0;
                    else {
                        int best = INT_MIN;
                        if (i > 0 && dp[i - 1][j][k] != INT_MIN)
                            best = max(best, dp[i - 1][j][k] + coins[i][j]);
                        if (j > 0 && dp[i][j - 1][k] != INT_MIN)
                            best = max(best, dp[i][j - 1][k] + coins[i][j]);
                        if (coins[i][j] < 0 && k > 0) {
                            if (i > 0 && dp[i - 1][j][k-1] != INT_MIN)
                                best = max(best, dp[i - 1][j][k-1]);
                            if (j > 0 && dp[i][j - 1][k-1] != INT_MIN)
                                best = max(best, dp[i][j - 1][k-1]);
                        }
                        dp[i][j][k] = best;
                    }
            }
        }
    }

    return max(dp[n - 1][m - 1][0],max(dp[n - 1][m - 1][1],dp[n - 1][m - 1][2]));
}
}
;