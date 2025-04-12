class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        long long n = ques.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i -= 1)
            dp[i] = max(ques[i][0] + dp[min((long long)ques[i][1] + i + 1, n)],
                        dp[i + 1]);
        return dp[0];
    }
};