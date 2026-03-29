class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s1;
        int n=prices.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i-=1){
            while(!s1.empty() && s1.top()>prices[i]){
                s1.pop();
            }
            if(s1.empty()){
                ans[i]=prices[i];
            }else{
                ans[i]=prices[i]-s1.top();
            }
            s1.push(prices[i]);
        }
        return ans;
    }
};