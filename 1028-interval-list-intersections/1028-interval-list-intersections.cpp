class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        int n=l1.size(),m=l2.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<n && j<m){
            int l=max(l1[i][0],l2[j][0]), r=min(l1[i][1],l2[j][1]);
            if(l<=r)
                ans.push_back({l,r});
            if(l1[i][1]<l2[j][1]) i++;
            else j++;
        }
        return ans;
    }
};