class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        bool flag = true;
        int i = 0, j = 0;
        while (i < word1.size() || j < word2.size()) {
            if (flag) {
                ans += word1[i];
                i += 1;
            } else {
                ans += word2[j];
                j += 1;
            }
            if (flag && j < word2.size()) {
                flag = false;
            } else if (!flag && i < word1.size()) {
                flag = true;
            }
        }
        return ans;
    }
};