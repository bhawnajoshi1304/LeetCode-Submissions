class Solution {
public:
    bool check(string t){
        int l=t.size()-1;
        if(t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o' || t[0]=='u'){
            if(t[l]=='a' || t[l]=='e' || t[l]=='i' || t[l]=='o' || t[l]=='u')
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int x=0;
        vector<int> ans, p(1,0);
        for(auto i:words){
            if(check(i)){
                x+=1;
            }
            p.push_back(x);
        }
        for(auto i:queries){
            ans.push_back(p[i[1]+1]-p[i[0]]);
        }
        return ans;
    }
};