class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        map<int,int> freq;
        for(auto i:arr){
            if(freq.find(i)==freq.end())
                freq[i]=1;
            else
                freq[i]+=1;
        }
        vector<int> candidates;
        for(auto i:freq)
            candidates.push_back(i.first);
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
                        bool f=true;
                        map<int,int> tmp;
                        for(auto y:x){
                            if(y.first==candidates[i]){
                                tmp[y.first]=y.second+1;
                            }else{   
                                 tmp[y.first]=y.second;
                             }
                            if(freq[y.first]<tmp[y.first]){
                                f=false;
                                break;
                            }
                        }
                        if(tmp.find(candidates[i])==tmp.end())
                            tmp[candidates[i]]=1;
                        if(f)
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