class Solution {
public:
    int myAtoi(string s) {
        map<char,int> digits;
        digits['0'] = 0;
        digits['1'] = 1;
        digits['2'] = 2;
        digits['3'] = 3;
        digits['4'] = 4;
        digits['5'] = 5;
        digits['6'] = 6;
        digits['7'] = 7;
        digits['8'] = 8;
        digits['9'] = 9;
         
        long long ans=0,n=0,start = INT_MAX, d=INT_MAX;
        for(long long j=0;j<s.size();j+=1){
            char i=s[j];
            if(digits.find(i)!=digits.end()){
                ans*=10;
                ans+=digits[i];
                start = min(start,j);
            }else if(i=='-' || i=='+'){
            if(j>start || j>d) break;
            if(i=='-')
            n=1;
            d=min(d,j);
            }
            else if(i==' ' && (j>start||j>d) ) break;
            else if(i!=' ' && i!='+') break;
        if(ans<INT_MIN) return INT_MIN;
        if(ans>INT_MAX) if(n==1) return INT_MIN; else return INT_MAX;
        }
        if(n==1) ans*=-1;
        return ans;
    }
};