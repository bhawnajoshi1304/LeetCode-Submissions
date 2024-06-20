class Solution {
public:
    bool canPlaceBalls(int gap, vector<int>& positions, int m) {
        int lastPosition = positions[0];
        int ballsRemaining = m - 1;
        for (int i = 1; i < positions.size() && ballsRemaining > 0; i++) {
            if (positions[i] - lastPosition >= gap) {
                ballsRemaining--;
                lastPosition = positions[i];
            }
        }
        return ballsRemaining == 0;
    }
    int maxDistance(vector<int>& positions, int m) {
        ios_base::sync_with_stdio(0);
        sort(positions.begin(), positions.end());
        int n = positions.size();
        int left = 1;
        int right = positions[n - 1] - positions[0];
        int maxMinDistance = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canPlaceBalls(mid, positions, m)) {
                maxMinDistance = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return maxMinDistance;
    }
};