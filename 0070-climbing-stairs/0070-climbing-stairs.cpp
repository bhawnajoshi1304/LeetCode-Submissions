class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 2, prev2 = 1, curr;
        if(n<3) return n;
        for (int i = 3; i <= n; i += 1) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};