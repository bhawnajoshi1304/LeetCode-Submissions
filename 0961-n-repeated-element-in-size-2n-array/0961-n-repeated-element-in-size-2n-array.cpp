class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            if(s.find(i)==s.end()){
                s.insert(i);
            }else return i;
        }
        return nums[0];
    }
};