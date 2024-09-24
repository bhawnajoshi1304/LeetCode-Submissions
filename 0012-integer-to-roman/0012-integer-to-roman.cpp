class Solution {
public:
    string intToRoman(int num) {
        map<int,char> m;
        m[1]='I';
        m[5]='V';
        m[10]='X';
        m[50]='L';
        m[100]='C';
        m[500]='D';
        m[1000]='M';
        vector<int> l{1000,500,100,50,10,5,1};
        string ans="";
        int i=0;
        while(i!=7 && num!=0){
            int tmp=num/l[i];
            if(tmp>=0){
                for(int j=0;j<tmp;j++){
                    ans+=m[l[i]];
                    num-=l[i];
                }
            }
                if(i%2==1){
                    if(num>=l[i]-l[i+1]){
                        ans+=m[l[i+1]];
                        ans+=m[l[i]];
                        num-=l[i]-l[i+1];
                    }
                }else{
                    if(i+2<=6 && num>=l[i]-l[i+2]){
                        ans+=m[l[i+2]];
                        ans+=m[l[i]];
                        num-=l[i]-l[i+2];
                    }
                }
                i+=1;
        }
        return ans;
    }
};