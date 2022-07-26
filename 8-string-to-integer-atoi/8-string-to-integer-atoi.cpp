class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        bool negative=false,positive=false,digit=false;
        for(auto i:s){
            if(i=='-'){
                if(digit||negative||positive) break;
                negative=true;
            }
            else if(i=='+'){
                if(digit||negative||positive) break;
                positive=true;
            }
            else if(i>='0' && i<='9'){
                if(digit==false) digit=true;
                if(negative && -1*ans<INT_MIN) return INT_MIN;
                if(ans>INT_MAX) return INT_MAX;
                ans*=10;
                ans+=i-'0';
            }else if((i==' '&& digit)||(i!='+'&&i!=' ')||((positive||negative)&&i==' ')){
                break;
            }
        }
        
        if(negative){
            if(positive) return 0;
            ans*=-1;
        }
        if(ans<INT_MIN) return INT_MIN;
        if(ans>INT_MAX) return INT_MAX;
        return ans;
    }
};