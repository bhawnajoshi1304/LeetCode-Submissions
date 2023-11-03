class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0;
        vector<string> ans;
        for(int i=1;i<=n;i+=1){
            if(target[j] == i){
                ans.push_back("Push");
                j+=1;
                if(j==target.size())
                break;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};