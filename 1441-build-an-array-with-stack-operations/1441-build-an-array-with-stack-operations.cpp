class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> s;
        vector<string> ans;
        int x=target.size(),i=0,c=1;
        while(i<x && c<=n){
            ans.push_back("Push");
            if(c!=target[i]){
                ans.push_back("Pop");
            }else{
                i+=1;
            }
            c+=1;
        }
        return ans;
    }
};