class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> s;
        for (const string& log : logs) {
            if (log == "../") {
                if (!s.empty()) {
                    s.pop_back();
                }
            } else if (log != "./") {
                s.push_back(log);
            }
        }
        return s.size();
    }
};