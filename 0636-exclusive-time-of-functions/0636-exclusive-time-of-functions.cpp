class Solution {
public:
    vector<string> split(string s, char c) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, c)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> s;
        vector<stack<int>> start(n);
        vector<int> ans(n, 0);
        for (auto i : logs) {
            vector<string> sp = split(i, ':');
            if (sp[1] == "start") {
                start[stoi(sp[0])].push(stoi(sp[2]));
                if (!s.empty()){
                    ans[s.top()] += stoi(sp[2]) - start[s.top()].top();
                    start[s.top()].pop();
                    }
                s.push(stoi(sp[0]));
            } else {
                ans[stoi(sp[0])] += stoi(sp[2]) - start[stoi(sp[0])].top()+1;
                s.pop();
                start[stoi(sp[0])].pop();
                if (!s.empty())
                    start[s.top()].push(stoi(sp[2])+1);
            }
        }
        return ans;
    }
};