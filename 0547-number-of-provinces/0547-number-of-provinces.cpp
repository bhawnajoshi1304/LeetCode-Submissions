class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int x, vector<bool>& visited,
             int n) {
        visited[x] = true;
        for (int i = 0; i < n; i += 1) {
            if (isConnected[x][i] && !visited[i])
                dfs(isConnected, i, visited, n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int c = 0, n = isConnected.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; i += 1) {
            if (!visited[i]) {
                c += 1;
                dfs(isConnected, i, visited, n);
            }
        }
        return c;
    }
};