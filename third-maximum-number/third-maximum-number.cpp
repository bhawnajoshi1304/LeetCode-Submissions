class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<long> s;
        for(auto i:nums){
            s.insert((long)-1*i);
        }
        long j=0,ans=*s.begin();
        for(auto i:s){
            if(j==3) break;
            j+=1;
            ans=i;
        }
        if(j!=3) return (-1)*(*s.begin());
        return ans*(-1);
    }
};