class Solution {
public:
    void generate(vector<string> &ans, string tmp, int n, int open,int curr){
        if(tmp.size()==n*2)
            ans.push_back(tmp);
        else if(curr==0){
            generate(ans,tmp+'(',n,open+1,curr+1);
        }else{
            if(open<n)
            generate(ans,tmp+'(',n,open+1,curr+1);
            generate(ans,tmp+')',n,open,curr-1);
        }
            
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,"",n,0,0);
        return ans;
    }
};