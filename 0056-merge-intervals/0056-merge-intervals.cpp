bool g(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), g);
        vector<int> t = intervals[0];
        for (int i = 1; i < int(intervals.size()); i++) {
            if (t[1] >= intervals[i][0])
                t[1] = max(t[1], intervals[i][1]);
            else {
                ans.push_back(t);
                t = intervals[i];
            }
        }
        ans.push_back(t);
        return ans;
    }
};