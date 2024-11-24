class Solution {
public:
    vector<vector<int>> ans;
    vector<int> l;
    vector<vector<int>> combinationSum(vector<int>& arr, int sum, int i = 0) {
        if (i >= arr.size()) {
            long long temp = 0;
            for (auto x : l)
                temp += x;
            if (temp == sum)
                ans.push_back(l);
            return ans;
        }
        long long temp = 0;
        for (auto i : l)
            temp += i;
        if (arr[i] + temp <= sum) {
            l.push_back(arr[i]);
            combinationSum(arr, sum, i);
            l.pop_back();
        }
        combinationSum(arr, sum, i+1);
        return ans;
    }
};