class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<map<int,int>>> ans(target);
        for(int i=0;i<candidates.size();i+=1){
            for(int j=0;j<target;j+=1){
                if(j+1-candidates[i]==0){
                    map<int,int> m;
                    m[j+1]=1;
                    ans[j].push_back(m);
                }
                if(j>=candidates[i]){
                    for(auto x: ans[j-candidates[i]]){
                        map<int,int> tmp;
                        for(auto y:x){
                            if(y.first==candidates[i]){
                                tmp[y.first]=y.second+1;
                            }else{   
                                 tmp[y.first]=y.second;
                             }
                        }
                        if(tmp.find(candidates[i])==tmp.end()){
                            tmp[candidates[i]]=1;
                            }
                        ans[j].push_back(tmp);
                    }
                }
            }
        }
        vector<vector<int>> a;
        for(auto x: ans[target-1]){
            vector<int> tmp;
            for(auto y:x){
                for(int i=0;i<y.second;i+=1)
                    tmp.push_back(y.first);
            }
            a.push_back(tmp);
        }
        return a;
    }
};