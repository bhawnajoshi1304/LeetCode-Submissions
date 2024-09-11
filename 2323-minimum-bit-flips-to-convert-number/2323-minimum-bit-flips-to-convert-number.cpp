class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start^goal;
        int ans=0;
        cout<<x<<"\n";
        while(x!=0){
            ans+=x%2;
            x=x/2;
        }
    return ans;
    }
};