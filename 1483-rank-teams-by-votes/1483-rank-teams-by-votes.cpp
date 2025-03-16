class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), m = votes[0].size();
        vector<vector<int>> rank(26, vector<int>(m, 0));
        vector<bool> present(26, false);
        for (string& vote : votes) {
            for (int pos = 0; pos < m; ++pos) {
                rank[vote[pos] - 'A'][pos]++;
                present[vote[pos] - 'A'] = true;
            }
        }
        auto cmp = [&](char a, char b) {
            for (int pos = 0; pos < m; ++pos) {
                if (rank[a - 'A'][pos] != rank[b - 'A'][pos])
                    return rank[a - 'A'][pos] > rank[b - 'A'][pos];
            }
            return a < b;
        };
        string teams;
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (present[c - 'A']) teams += c;
        }
        sort(teams.begin(), teams.end(), cmp);
        return teams;
    }
};
