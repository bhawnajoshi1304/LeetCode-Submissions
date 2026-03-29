class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        for(auto i:nums)
        s.insert(i);
        int n=nums.size();
        vector<int> ans;
        for(int i=1;i<=n;i+=1){
            if(s.find(i)==s.end()) ans.push_back(i);
        }
        return ans;
    }
};