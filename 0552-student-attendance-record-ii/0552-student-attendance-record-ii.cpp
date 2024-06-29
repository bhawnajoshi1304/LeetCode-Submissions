class Solution {
    const int MOD = 1000000007;

    int solve(int num, int absentCount, int lateCount, int n, vector<vector<vector<int>>>& dp) {
        // Base case: if num exceeds n, return 1
        if (num > n)
            return 1;
        // Check if this state has already been computed
        if (dp[num][absentCount][lateCount] != -1)
            return dp[num][absentCount][lateCount];

        // Calculate the number of valid sequences by adding an 'A'
        int absent = absentCount < 1 ? solve(num + 1, absentCount + 1, 0, n, dp) : 0;
        // Calculate the number of valid sequences by adding an 'L'
        int late = lateCount < 2 ? solve(num + 1, absentCount, lateCount + 1, n, dp) : 0;
        // Calculate the number of valid sequences by adding a 'P'
        int present = solve(num + 1, absentCount, 0, n, dp);

        // Sum the results and apply modulo
        dp[num][absentCount][lateCount] = ((absent + late) % MOD + present % MOD) % MOD;
        return dp[num][absentCount][lateCount];
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, -1)));
        // Start solving from day 1 with 0 absents and 0 lates
        return solve(1, 0, 0, n, dp);
    }
};