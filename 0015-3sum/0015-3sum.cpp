class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == -nums[i]) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (nums[left] == ans[ans.size() - 1][1] &&
                           left < nums.size() - 1)
                        left += 1;
                    while (nums[right] == ans[ans.size() - 1][2] && right > 0)
                        right -= 1;
                } else if (nums[left] + nums[right] > -nums[i]) {
                    while (nums[right - 1] == nums[right] && right > 1)
                        right -= 1;
                    right -= 1;
                } else {
                    while (nums[left + 1] == nums[left] &&
                           left < nums.size() - 3)
                        left += 1;
                    left += 1;
                }
            }
            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                i += 1;
        }
        return ans;
    }
};