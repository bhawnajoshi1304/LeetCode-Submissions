class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xo=0;
        for(auto i:nums) xo^=i;
        for(int i=0;i<=nums.size();i+=1) xo^=i;
        return xo;
    }
};