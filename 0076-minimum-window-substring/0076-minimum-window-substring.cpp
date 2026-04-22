class Solution {
public:
    bool check(map<char,int> &m) {
        for (auto i : m) {
            if (i.second < 0)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.size() == 0)
            return "";
        map<char, int> m;
        int j = 0, le = 0, ml = INT_MAX;
        string ans = "";
        for (auto i : t)
            m[i] -= 1;
        for (int i = 0; i < s.size(); i += 1) {
            if (t.size() == 1 && s[i] == t[0])
                return t;
            m[s[i]] += 1;
            if (check(m)) {
                while (j < i && m[s[j]] > 0) {
                    m[s[j]] -= 1;
                    j++;
                }
                le = i - j + 1;
                if (le < ml) {
                    ml = le;
                    ans = s.substr(j, le);
                }
            }
        }
        return ans;
    }
};