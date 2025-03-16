class Solution {
public:
    bool valid(int i, int j, int n, int m, vector<vector<int>>& matrix) {
        return (i < n && j < m && i >= 0 && j >= 0 && matrix[i][j] != INT_MIN);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans, y = {1, 0, -1, 0}, x = {0, 1, 0, -1};
        int d = 0;
        int n = matrix.size(), m = matrix[0].size(), i = 0, j = 0;
        while (ans.size() != n * m) {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            if (!valid(i + x[d], j + y[d], n, m, matrix)) {
                d = (d + 1) % 4;
            }
            i += x[d];
            j += y[d];
        }
        return ans;
    }
};