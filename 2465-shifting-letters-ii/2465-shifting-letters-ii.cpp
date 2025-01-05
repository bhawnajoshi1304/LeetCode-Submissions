class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefix(s.size()+1,0);
        for(int i=0;i<shifts.size();i+=1){
            int d=shifts[i][2]?1:-1;
            prefix[shifts[i][0]]+=d;
            prefix[shifts[i][1]+1]-=d;
        }
        int x=0;
        for(int i=0;i<s.size();i+=1){
            x+=prefix[i];
            int d=(s[i]-'a'+x)%26;
            if(d<0)
            d+=26;
            cout<<x<<"->"<<d<<" ";
            s[i]='a'+d;
        }
        return s;
    }
};