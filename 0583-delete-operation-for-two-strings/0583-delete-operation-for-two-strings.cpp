class Solution {
public:
    int minDistance(string word1, string word2) {
        // String1: s ea
        // String2:   ea t
        // LCS:       ea
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                if(word1[i]==word2[j])
                dp[i][j]=(i==0 || j==0)? 1: dp[i-1][j-1]+1;
                else
                dp[i][j]=max(i>0?dp[i-1][j]:0,j>0?dp[i][j-1]:0);
                    
            }
        }
        return m+n-2*dp[n-1][m-1];
    }
};