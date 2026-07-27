class Solution {
public:
    int distanceBetweenBusStops(vector<int>& sum, int a, int b) {
        int n = sum.size();
        vector<int> distance(n + 1);
        for (int i = 0; i < n; i++) {
            distance[i + 1] = distance[i] + sum[i];
            cout << distance[i + 1] << " ";
        }
        if (a <= b)
            return min(distance[b] - distance[a],
                       distance[n] - distance[b] + distance[a]);

        return min(distance[a] - distance[b],
                   distance[n] - distance[a] + distance[b]);
    }
};