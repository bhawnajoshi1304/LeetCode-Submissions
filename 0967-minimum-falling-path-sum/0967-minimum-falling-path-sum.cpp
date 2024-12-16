class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i+=1){
            for(int j=0;j<n;j+=1){
                if(i==0)
                dp[i][j]=matrix[i][j];
                if(i>0 && j>0)
                dp[i][j]=min(dp[i-1][j-1]+matrix[i][j],dp[i][j]);
                if(i>0)
                dp[i][j]=min(dp[i-1][j]+matrix[i][j],dp[i][j]);
                if(i>0 && j+1<n)
                dp[i][j]=min(dp[i-1][j+1]+matrix[i][j],dp[i][j]); 
                cout<<dp[i][j]<<" "; 
            }
            cout<<"\n";

        }
        int ans=INT_MAX;
        for(int j=0;j<n;j+=1){
            ans=min(ans,dp[m-1][j]);
        }
        return ans;
    }
};