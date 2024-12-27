class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i+=1){
            for(int j=coins[i];j<=amount;j+=1){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};