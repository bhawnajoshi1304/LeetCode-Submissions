class Solution {
private:
    void dfs(vector<bool>& visited, vector<vector<int>>& isConnected, int x) {
        for (int i = 0; i < isConnected[x].size(); i++) {
            if (isConnected[x][i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(visited, isConnected, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0, n = isConnected.size();
        vector<bool> visited(n,false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(visited, isConnected, i);
                ans++;
            }
        }
        return ans;
    }
};