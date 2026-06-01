class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int i=0,ans=0;
        while(i<cost.size()){
            if(i+1<cost.size()) ans+=cost[i+1];
            ans+=cost[i];
            i+=3;
        }
        return ans;
    }
};