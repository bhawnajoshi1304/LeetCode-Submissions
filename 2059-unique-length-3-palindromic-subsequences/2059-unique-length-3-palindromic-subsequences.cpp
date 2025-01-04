class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> a(26,-1),triplets(26,0);
        int ans=0,n=s.size();
        for(int i=0;i<n;i+=1){
            if(a[s[i]-'a']!=-1){
                ans+=i-a[s[i]-'a']-1;
                a[s[i]-'a']=i;
                triplets[s[i]-'a']+=1;
                if(triplets[s[i]-'a']==3)
                ans+=1;
            }else{
                a[s[i]-'a']=i;
                triplets[s[i]-'a']+=1;
            }
        }
        return ans;
    }
};