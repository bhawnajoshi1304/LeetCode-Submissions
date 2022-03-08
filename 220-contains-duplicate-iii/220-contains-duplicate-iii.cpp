class Solution {
public:
    int min(int a, int b){
        if(a>b) return b;
        return a;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()==1 || k==0) return false;
        multiset<long> s;
        for(int i=0;i<min(k,nums.size());i+=1){
            if(i>0){
                auto x=s.lower_bound((long)nums[i]-t);
                if(x!=s.end() && nums[i]- *x>=-t)
                    return true;
            }
            s.insert(nums[i]);
        }
        for(int i=k;i<nums.size();i+=1){
            auto x=s.lower_bound((long)nums[i]-t);
            if(x!=s.end() && nums[i]- *x>=-t)
                return true;
            s.erase(s.lower_bound(nums[i-k]));
            s.insert(nums[i]);
        }
        return false;
    }
};