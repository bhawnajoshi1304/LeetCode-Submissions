class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (i == 0)
                    curr[j] = prev[j] = matrix[i][j];
                else {
                    curr[j] = prev[j] + matrix[i][j];
                    if (i > 0 && j > 0)
                        curr[j] = min(prev[j - 1] + matrix[i][j], curr[j]);
                    if (i > 0 && j + 1 < n)
                        curr[j] = min(prev[j + 1] + matrix[i][j], curr[j]);
                }
            }
            for (int j = 0; j < n; j += 1)
                prev[j]=curr[j];
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j += 1) {
            ans = min(ans, curr[j]);
        }
        return ans;
    }
};