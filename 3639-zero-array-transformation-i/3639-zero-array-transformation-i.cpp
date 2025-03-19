class Solution {
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        vector<int> diffArray(n+1, 0);
        for(int i = 0; i < queries.size(); i++) {
            diffArray[queries[i][0]] += 1;
            diffArray[queries[i][1] + 1] -= 1;
        }
        for(int i = 1; i < diffArray.size(); i++) {
            diffArray[i] += diffArray[i - 1];
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > diffArray[i]) return false;
        }
        return true;
    }
};