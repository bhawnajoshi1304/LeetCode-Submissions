class Solution {
public:    int minSwaps(vector<int>& nums) {
        int s = nums.size();
        int ones = 0;
        for (int n : nums) {
            ones += n;
        }
        if (ones == 0 || ones == s) {
            return 0;
        }
        int curr = 0;
        for (int i = 0; i < ones; i++) {
            curr += nums[i];
        }
        int maxi = curr;
        for (int i = 0; i < s; i++) {
            curr -= nums[i];
            curr += nums[(i + ones) % s];
            maxi = max(maxi, curr);
        }
        return ones - maxi;
    }

};