class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,pair<int, int>> s;
        int c = 0;
        for (auto i : nums) {
            if (s.find(i)!=s.end()) {
                auto [a, b] = s[i];
                if (a != -1)
                    ans = min(ans, 2 * (c - a));
                s[i] = {b, c};
            } else {
                s[i] = {-1, c};
            }
            c++;
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};