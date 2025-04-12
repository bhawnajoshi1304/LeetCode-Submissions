class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxTriplet = 0, maxNum = 0, maxDiff = 0;
        for (long num : nums) {
            maxTriplet = max(maxTriplet, maxDiff * num);
            maxDiff = max(maxDiff, maxNum - num);
            maxNum = max(maxNum, num);
        }
        return maxTriplet;
    }
};