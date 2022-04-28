class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<long> s;
        for(auto it:nums) s.insert(it);
        vector<int> ans;
        int c=1;
        for(auto it:s){
            while(it!=c){
                ans.push_back(c);
                c+=1;
            }
            c+=1;
        }
        while(c!=nums.size()+1){
            ans.push_back(c);
                c+=1;
        }
        return ans;
    }
};