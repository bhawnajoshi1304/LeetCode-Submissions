class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, curr = -1;
        map<char, int> m;
        for (int i = 0; i < s.size(); i += 1) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            } else {
                ans = max(ans, i - (curr + 1));
                curr = max(curr, m[s[i]]);
                ans = max(i - curr, ans);
                m[s[i]] = i;
            }
        }
        ans = max((int)s.size() - 1 - curr, ans);
        return ans;
    }
};