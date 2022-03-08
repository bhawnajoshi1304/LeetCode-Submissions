class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        vector<int> ans;
        for(auto i:nums1)
            s.insert(i);
        for(auto i:nums2){
            auto x=s.lower_bound(i);
            if(x!=s.end() && i==*x){
                s.erase(x);
                ans.push_back(i);
            }
        }
        return ans;
    }
};