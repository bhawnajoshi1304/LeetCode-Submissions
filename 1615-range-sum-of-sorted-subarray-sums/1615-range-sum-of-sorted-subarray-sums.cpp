
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int>subarraySums;
        // Generate all subarray sums
        for(int i = 0; i < n;i++){
            int currentSum = 0;
            for(int j = i; j < n; j++){
                currentSum+=nums[j];
                subarraySums.push_back(currentSum);
            }
        }
        // Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());
        // Compute the sum of elements from index left to right (1-based index)
        int sum = 0;
        for(int i = left - 1; i < right; i++){
            sum = (sum + subarraySums[i]) % MOD;
        }
        return sum;
    }
};