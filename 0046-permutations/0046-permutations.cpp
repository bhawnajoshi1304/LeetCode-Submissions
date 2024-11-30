class Solution {
public:
    void generatePermutations(vector<int>& nums, vector<vector<int>>& ans, int ind = 0) {
        if (ind == nums.size() - 1)
            ans.push_back(nums);
        for (int i = ind; i < nums.size(); i += 1) {
            swap(nums[i], nums[ind]);
            generatePermutations(nums, ans, ind+1);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermutations(nums, ans);
        return ans;
    }
};