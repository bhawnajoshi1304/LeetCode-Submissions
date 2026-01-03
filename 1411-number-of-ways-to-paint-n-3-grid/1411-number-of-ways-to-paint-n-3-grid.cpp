class Solution {
public:
    int numOfWays(int n) {
        /*
        ABA  ABC
        
        ABA ABA ABA
        BAB CAC BCB 

        ABA ABA 
        BAC CAB

        ABC ABC
        BAB CAC

        ABC ABC
        CAB BCA                       
        */
        long long a=6,b=6,na=0,nb=0,mod=1e9+7;
        for(int i=2;i<=n;i+=1){
            na=((3*a)%mod+(2*b)%mod)%mod;
            nb=((2*a)%mod+(2*b)%mod)%mod;
            a=na;
            b=nb;
        }
        return (a+b)%mod;
    }
};