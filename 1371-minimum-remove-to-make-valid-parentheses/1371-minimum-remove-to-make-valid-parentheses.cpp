class Solution {
public:
    string minRemoveToMakeValid(string str) {
        string ans = "";
        int c = 0;
        for (auto i : str) {
            if (i == '(') {
                c += 1;
                ans+=i;
            } else if (i == ')') {
                if (c > 0) {
                    c -= 1;
                    ans+=i;
                }
            } else {
                ans+=i;
            }
        }
        c = 0;
        string tmp=ans;
        ans="";
        for(int i=tmp.size()-1;i>=0;i-=1) {
            char ch = tmp[i];
            if (ch == ')') {
                c -= 1;
                ans += ch;
            } else if (ch == '(') {
                if (c < 0) {
                    c += 1;
                    ans += ch;
                }
            } else {
                ans += ch;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};