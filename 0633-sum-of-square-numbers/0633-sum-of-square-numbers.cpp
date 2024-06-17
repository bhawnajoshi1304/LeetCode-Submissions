class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int s = 0, e = sqrt(c);
        int mid = s+(e-s)/2;
        while(s<=e){
            if(s*s>c)return false;
            if(s*s+e*e == c)return true;
            else if(s*s + e*e>c)e--;
            else s++;
            
        }
        return false;
    }
};