class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res = "";
        vector<int> counts;
        for (char c : s) {
            if (!res.empty() && res.back() == c) {
                res.push_back(c);
                counts.push_back(counts.back() + 1);
            } else {
                res.push_back(c);
                counts.push_back(1);
            }
            if (counts.back() == k) {
                for (int i = 0; i < k; i++) {
                    res.pop_back();
                    counts.pop_back();
                }
            }
        }
        return res;
    }
};