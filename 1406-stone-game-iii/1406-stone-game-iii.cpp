class Solution {
public:
    int score(vector<vector<int>>& dp, int idx) {
        if (idx >= 0 && idx < dp.size())
            return dp[idx][3];
        return 0;
    }
    int sum(vector<int>& s, int i, int j) {
        int x = s[i];
        while (j) {
            if (i + 1 < s.size())
                x += s[i + 1];
            i += 1;
            j -= 1;
        }
        return x;
    }
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> d(n, vector<int>(4));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j += 1) {
                d[i][j] = sum(s, i, j) - score(d, i + 1 + j);
                if (j > 0)
                    d[i][3] = max(d[i][j], d[i][3]);
                else d[i][3] = d[i][0];
            }
        }
        if (d[0][3] == 0)
            return "Tie";
        return d[0][3] > 0 ? "Alice" : "Bob";
    }
};