class Solution {
public:
    void subsets(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &ans, int i=0){
        ans.push_back(tmp);
        for(int j=i;j<nums.size();j+=1){
            if(j==i || nums[j]!=nums[j-1]){
                tmp.push_back(nums[j]);
                subsets(nums,tmp,ans,j+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        subsets(nums,tmp,ans);
        return ans;
    }
};