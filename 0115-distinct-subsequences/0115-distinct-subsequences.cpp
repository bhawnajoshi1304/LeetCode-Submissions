class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size(),prime = 1e9+7;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0]=1;
        for (int i = 1; i <= n; i += 1) {
            dp[i][0]=1;
            for (int j = 1; j <= m; j += 1) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%prime;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};