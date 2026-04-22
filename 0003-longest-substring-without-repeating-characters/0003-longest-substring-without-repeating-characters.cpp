class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, curr = -1;
        map<char, int> m;
        for (int i = 0; i < s.size(); i += 1) {
            cout << s[i] << "\n";
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            } else {
                if (curr == -1) {
                    ans = max(ans, i);
                    cout << i << " " << ans << "\n";
                } else {
                    ans = max(ans, i - curr - 1);
                    cout << i << " " << ans << "\n";
                }
                ans = max(i - max(curr,m[s[i]]), ans);
                cout << i << " " << m[s[i]] << " " << ans << "\n";
                curr = max(curr,m[s[i]]);
                m[s[i]] = i;
                cout << "*" << curr << " " << m[s[i]] << " " << ans << "\n";
            }
        }
        ans = max((int)s.size() - 1 - curr, ans);
        return ans;
    }
};