class Solution {
public:

void findCombinations(vector<int>& arr, int sum, vector<int>& l, vector<vector<int>>& ans, int i=0) {  
        if (sum==0) {
            ans.push_back(l);
            return;
        }
        for (int j = i; j < arr.size(); j += 1) {
            if ((j == i || arr[j] != arr[j - 1]) && sum-arr[j]>=0) {
                l.push_back(arr[j]);
                findCombinations(arr, sum-arr[j], l, ans,j+1);
                l.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int sum, int i = 0) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> l;
        findCombinations(arr, sum, l, ans);
        return ans;
    }
};