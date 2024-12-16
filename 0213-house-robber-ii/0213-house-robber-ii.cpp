class Solution {
public:
    int solve(vector<int> nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int curr = INT_MIN, prev1 = INT_MIN, prev2 = INT_MIN;
        if (n >= 1)
            prev2 = nums[0];
        if (n >= 2)
            prev1 = max(nums[0], nums[1]);
        curr = max(prev1, prev2);
        for (int i = 2; i < n; i += 1) {
            curr = max(prev1, nums[i] + prev2);
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        return max(solve(vector<int>(nums.begin(), nums.end() - 1)),
                   solve(vector<int>(nums.begin() + 1, nums.end())));
    }
};