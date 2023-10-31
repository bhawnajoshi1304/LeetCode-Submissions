class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        if(pref.size() == 0) return ans;
        ans.push_back(pref[0]);
        for(int i=1;i<pref.size();i+=1){
            ans.push_back(pref[i-1]^pref[i]);
            }
        return ans;
    }
};