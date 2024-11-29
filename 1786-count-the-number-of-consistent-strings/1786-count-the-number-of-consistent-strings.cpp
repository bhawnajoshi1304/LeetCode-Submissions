class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> ch(26,false);
        for(auto i:allowed){
            ch[i-'a']=true;
        }
        int ans=0,c=0;
        for(auto i:words){
            c=0;
            for(auto j:i){
                if(ch[j-'a'])
                c+=1;
                else break;
            }
            if(c==i.size()) ans+=1;

        }
        return ans;
    }
};