class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int dfs(vector<vector<int>>& grid, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        int best = max({
            dfs(grid, r1 + 1, c1, c2 + 1),
            dfs(grid, r1, c1 + 1, c2 + 1),
            dfs(grid, r1 + 1, c1, c2),
            dfs(grid, r1, c1 + 1, c2)
        });

        return dp[r1][c1][c2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, dfs(grid, 0, 0, 0));
    }
};
