class Solution {
public:
    void findCombinations(vector<int>& arr, int sum, int i, vector<int>& l,
                          vector<vector<int>>& ans) {
        long long temp = 0;
        for (auto x : l)
            temp += x;
        if (temp == sum) {
            ans.push_back(l);
            return;
        }
        for (int j = i; j < arr.size(); j += 1) {
            if (j > i && arr[j] == arr[j - 1])
                continue;
            if (arr[j] + temp <= sum) {
                l.push_back(arr[j]);
                findCombinations(arr, sum, j + 1, l, ans);
                l.pop_back();
            }else break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int sum, int i = 0) {
        sort(arr.begin(), arr.end());
        for(auto i: arr)cout<<i<<" ";
        cout<<"\n";
        vector<vector<int>> ans;
        vector<int> l;
        findCombinations(arr, sum, 0, l, ans);
        return ans;
    }
};