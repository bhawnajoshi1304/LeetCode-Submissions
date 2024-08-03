class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> m;
        for(auto i: arr){
            if(m.find(i)!=m.end())
            m[i]+=1;
            else m[i]=1;
        }
        for(auto i: target){
            if(m.find(i)!=m.end())
            m[i]-=1;
            else m[i]=-1;
        }

        for(auto i: m){
            if(i.second!=0)return false;
        }
        return true;
    }
};