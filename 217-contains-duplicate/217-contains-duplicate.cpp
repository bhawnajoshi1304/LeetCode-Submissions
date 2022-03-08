class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums)
            if(m.find(i)==m.end())
                m[i]=1;
        else return true;
        return false;
    }
};