class Solution {
public:
    int min(int a,int b){
    if(a>b) return b;
    else return a;}
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for(int i=0;i<min(k,nums.size());i+=1)
            if(s.find(nums[i])==s.end())
                s.insert(nums[i]);
            else return true;
        for(int i=k;i<nums.size();i+=1){
            if(s.find(nums[i])==s.end())
                s.insert(nums[i]);
            else return true;
            s.erase(nums[i-k]);
        }
        return false;
    }
};