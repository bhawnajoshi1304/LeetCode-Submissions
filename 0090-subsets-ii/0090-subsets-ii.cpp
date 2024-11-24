class Solution {
public:
    void powerset(vector<vector<int>> &ans, vector<int> a,int x){
        if(x<a.size()){
            int N=ans.size();
            for(int i=0;i<N;i+=1){
                vector<int> tmp;
                for(int j=0;j<ans[i].size();j+=1)
                    tmp.push_back(ans[i][j]);
                tmp.push_back(a[x]);
                sort(tmp.begin(),tmp.end());
                ans.push_back(tmp);
            }
            powerset(ans,a,x+1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans(1);
        powerset(ans,nums,0);
        set<vector<int>> s;
        for(auto i:ans)
            s.insert(i);
        vector<vector<int>> a;
        for(auto i:s)
            a.push_back(i);
        return a;
    }
};