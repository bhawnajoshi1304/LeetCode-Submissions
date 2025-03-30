class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int i = 0, j = nums.size(), k = 0;
        for (i = 0; i < nums.size(); i += 1) {
            if (nums[i] == 0) {
                ans[--j] = 0;
            } else {
                if (i+1 < nums.size() && nums[i] == nums[i + 1]) {
                    ans[k++] = nums[i++] * 2;
                    ans[--j] = 0;
                } else {
                    ans[k++] = nums[i];
                }
            }
        }
        return ans;
    }
};