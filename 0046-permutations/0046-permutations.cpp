class Solution {
public:
    void generatePermutations(vector<int> &nums,vector<int> &tmp, vector<bool> &flag, vector<vector<int>> &ans){
        if(tmp.size() == nums.size()) {ans.push_back(tmp);return;}
        for(int i=0;i<nums.size();i+=1){
            if(!flag[i]){
                tmp.push_back(nums[i]);
                flag[i] = true;
                generatePermutations(nums,tmp,flag,ans);
                tmp.pop_back();
                flag[i]=false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> flag(nums.size(),false);
        generatePermutations(nums,tmp,flag,ans);
        return ans;
    }
};