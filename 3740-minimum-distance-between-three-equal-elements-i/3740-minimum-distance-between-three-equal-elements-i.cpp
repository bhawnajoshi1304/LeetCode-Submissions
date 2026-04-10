class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        vector<pair<int, int>> s(101, {-1, -1});
        int c = 0;
        for (auto i : nums) {
            auto [a, b] = s[i];
            if (b != -1) {
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