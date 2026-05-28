class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    vector<string> adj(int i, int j, vector<vector<int>> &grid) {
        vector<string> ans;
        int n = grid.size(), m = grid[0].size();
        vector<int> dy = {-1, 0, 1, 0}, dx = {0, -1, 0, 1};
        for (int a = 0; a < 4; a += 1) {
            if (isValid(i + dx[a], j + dy[a], n, m) &&
                grid[i + dx[a]][j + dy[a]] == 1) {
                ans.push_back(to_string(i + dx[a]) + ":" +
                              to_string(j + dy[a]));
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        map<string, vector<string>> m;
        set<string> dfs,dfs2;
        int c = 0, ans = 0;
        for (int i = 0; i < grid.size(); i += 1) {
            for (int j = 0; j < grid[i].size(); j += 1) {
                if (grid[i][j] != 0) {
                    m[to_string(i) + ":" + to_string(j)] = adj(i, j, grid);
                    if (grid[i][j] == 1)
                        c += 1;
                    else if (grid[i][j] == 2)
                        dfs.insert(to_string(i) + ":" + to_string(j));
                }
            }
        }
        int ini = dfs.size();
        while (c != 0) {
            ini = dfs.size();
            for (auto i : dfs) {
                for (auto mp : m[i]) {
                    dfs2.insert(mp);
                }
            }
            for(auto j:dfs2)
            dfs.insert(j);
            if (ini != dfs.size()) {
                ans += 1;
                c -= dfs.size() - ini;
            } else {
                break;
            }
        }
        if (c != 0)
            return -1;
        return ans;
    }
};