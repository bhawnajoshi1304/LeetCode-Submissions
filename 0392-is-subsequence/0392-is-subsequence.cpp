class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i+=1;
                j+=1;
            }else{
                j+=1;
            }
        }
        return (i>int(s.size())-1);
    }
};