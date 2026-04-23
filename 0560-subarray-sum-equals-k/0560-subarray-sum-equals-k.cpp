class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> c;
        c[nums[0]] = 1;
        int ans = 0;
        if (nums[0] == k)
            ans += 1;
        for (int i = 1; i < nums.size(); i += 1) {
            nums[i] += nums[i - 1];
            ans += c[nums[i] - k];
            c[nums[i]] += 1;
            if (nums[i] == k)
                ans += 1;
        }
        return ans;
    }
};
// [-1,-2,-1]
// -2 ->1
// -1 ->2