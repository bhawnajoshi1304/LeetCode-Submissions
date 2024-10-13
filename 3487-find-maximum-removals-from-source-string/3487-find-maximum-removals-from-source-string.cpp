class Solution {
public:
    int maxRemovals(string A, string B, vector<int>& targetIndices) {
        int n = A.size(), m = B.size();
        unordered_set<int> target(targetIndices.begin(), targetIndices.end());

        vector<int> dp(m + 1, INT_MIN);
        dp[m] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= m; ++j) {
                dp[j] += target.count(i);
                if (j < m && A[i] == B[j]) {
                    dp[j] = max(dp[j], dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};