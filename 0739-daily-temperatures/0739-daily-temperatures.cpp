class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> t;
        for(int i=n-1;i>=0;i-=1){
            while(!t.empty() && temperatures[i] >= t.top().first){
                t.pop();
            }
            if(!t.empty()){
                ans[i] = t.top().second-i;
            }
            t.push({temperatures[i],i});
        }
        return ans;
    }
};