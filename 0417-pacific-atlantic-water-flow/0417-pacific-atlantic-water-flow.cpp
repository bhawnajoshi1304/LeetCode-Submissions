class Solution {
public:
    vector<vector<int>> di = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j < m && j >= 0);
    }
    void dfs(vector<vector<int>>& visited, vector<vector<int>>& heights, int i,
             int j, vector<vector<int>>& ans, bool flag) {

        if (!flag && (visited[i][j] == 1 || visited[i][j] == 3))
            return;
        if (flag && (visited[i][j] == 2 || visited[i][j] == 3))
            return;
        if (visited[i][j] == 1 && flag) {
            ans.push_back({i, j});
            visited[i][j] = 3;
        } else if (visited[i][j] == 0) {
            visited[i][j] = flag ? 2 : 1;
        }
        for (int a = 0; a < 4; a += 1) {
            if (isValid(i + di[a][0], j + di[a][1], heights.size(),
                        heights[0].size())) {
                if (heights[i][j] <= heights[i + di[a][0]][j + di[a][1]])
                    dfs(visited, heights, i + di[a][0], j + di[a][1], ans,
                        flag);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> visited(heights.size(),
                                    vector<int>(heights[0].size())),
            ans;
        for (int i = 0; i < heights[0].size(); i += 1) {
            dfs(visited, heights, 0, i, ans, false);
        }
        for (int i = 0; i < heights.size(); i += 1) {
            dfs(visited, heights, i, 0, ans, false);
        }
        for (int i = 0; i < heights[0].size(); i += 1) {
            dfs(visited, heights, heights.size() - 1, i, ans, true);
        }
        for (int i = 0; i < heights.size(); i += 1) {
            dfs(visited, heights, i, heights[0].size() - 1, ans, true);
        }
        return ans;
    }
};