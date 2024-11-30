class Solution {
public:
    void generateSubsets(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& ans, int i = 0) {
        ans.push_back(tmp);
        for (int j = i; j < nums.size(); j += 1) {
            tmp.push_back(nums[j]);
            generateSubsets(nums, tmp, ans, j + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        generateSubsets(nums, tmp, ans);
        return ans;
    }
};