class Solution {
public:
    bool checkPalindrome(string s){
        cout<<s<<" ";
        if(s.size()==1) return true;
        for(int i=0;i<s.size()/2;i+=1){
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        int c=0;
        while(i<j){
            // cout<<i<<" "<<j<<"\n";
            if(s[i]==s[j]){
                i+=1;
                j-=1;
            }else
        return checkPalindrome(s.substr(i,j-i))||checkPalindrome(s.substr(i+1,j-i));
        }
        return true;
    }
};