class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            if(m.find(i)!=m.end())
            m[i]+=1;
            else
            m[i]=1;
        }
        for(auto i: m){
            if(i.second%2) return false;
        }
        return true;
    }
};