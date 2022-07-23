class Solution {
public:
    void partition(string s, int x, vector<vector<string>> &ans, vector<string> &tmp){
        if(x==s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=x;i<s.size();i+=1){
            if(palindrome(s.substr(x,i+1-x))){
                tmp.push_back(s.substr(x,i+1-x));
                partition(s,i+1,ans,tmp);
                tmp.pop_back();
            }
        }
    }
    bool palindrome(string s){
        int i=0;
        while(2*i<=s.size()){
            if(s[i]!=s[s.size()-i-1]) return false;
            i+=1;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        partition(s,0,ans,tmp);
        return ans;
    }
};