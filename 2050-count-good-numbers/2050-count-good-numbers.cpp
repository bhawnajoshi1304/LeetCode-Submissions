class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodNumbers(long long digit) {
        long long even = (digit + 1) / 2;
        long long odd = digit / 2;

        long long evenWays = ways(5, even);
        long long oddWays = ways(4, odd);

        return (evenWays * oddWays) % MOD;
    }

    long long ways(long long base, long long power) {
        long long result = 1;
        base %= MOD;

        while (power > 0) {
            if (power % 2 == 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            power /= 2;
        }

        return result;
    }
};