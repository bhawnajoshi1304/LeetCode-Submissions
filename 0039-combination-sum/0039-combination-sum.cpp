class Solution {
public:
static void solve(int i, int target, vector<int> &candidates,vector<vector<int>> &ans,vector<int> tmp){
    if(i>=candidates.size()) return;
    if(candidates[i]<=target){
        tmp.push_back(candidates[i]);
        if(candidates[i] == target){
            ans.push_back(tmp);
        }else{
            solve(i,target-candidates[i],candidates,ans,tmp);
        }
        tmp.pop_back();
    }
    solve(i+1,target,candidates,ans,tmp);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0,target,candidates,ans,tmp);
        return ans;
    }
};