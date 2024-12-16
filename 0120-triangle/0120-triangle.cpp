class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<long> dp(n), prev(n);
        for (long i = n - 1; i >= 0; i -= 1) {
            for (long j = 0; j <= i; j += 1) {
                if (i != n - 1)
                    prev[j] = min(dp[j], dp[j + 1]);
                prev[j] += triangle[i][j];
            }
            for (long j = 0; j <= i; j += 1)
                dp[j] = prev[j];
        }
        return dp[0];
    }
};