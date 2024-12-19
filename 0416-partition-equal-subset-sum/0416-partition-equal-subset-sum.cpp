class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum = 0, n = arr.size();
        for (long long i = 0; i < n; i++)
            sum += arr[i];
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        vector<bool> t(sum + 1, false);
        t[0] = true;
        for (long long i = 1; i <= n; i++) {
            for (long long j = sum; j >= arr[i-1]; j--) {
                    t[j] = t[j - arr[i - 1]] || t[j];
            }
        }
        return t[sum];
    }
};
