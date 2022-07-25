class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows,"");
        string ans="";
        int i=0,j=0,c=0;
        while(j<s.size()){
            v[i]+=s[j];
            if(numRows==1) c=0;
            else if(i==numRows-1) c=-1;
            else if(i==0) c=1;
            i+=c;
            j+=1;
        }
        for(int i=0;i<numRows;i+=1){
            for(auto j:v[i]){
                ans+=j;
            }
        }
        return ans;
    }
};