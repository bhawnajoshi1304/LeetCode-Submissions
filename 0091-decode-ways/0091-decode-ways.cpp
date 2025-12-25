class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        vector<int> dp(s.size()+1);
        dp[0]=1;
        dp[1]=s[0]!='0' ? 1:0;
        for(int i=2;i<=s.size();i+=1){
            int a=stoi(s.substr(i-1,1)), b=stoi(s.substr(i-2,2));
            if(a>=1 && a<=9)
            dp[i]+=dp[i-1];
            if(b>=10 && b<=26)
            dp[i]+=dp[i-2];
        }
        return dp[s.size()];
    }
};