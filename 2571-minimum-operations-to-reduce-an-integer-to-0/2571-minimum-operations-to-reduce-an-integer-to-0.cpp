class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n > 0) {
            if (n & 1) {
                ans++;
                if (n & 2) {
                    n += 1;
                } else {
                    n -= 1;
                }
            }
            n >>= 1;
        }
        return ans;
    }
};