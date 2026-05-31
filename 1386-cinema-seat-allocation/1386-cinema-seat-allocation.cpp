class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // options to check are 4-7 or 2-5 or 6-9
        // effective check 2-9
        unordered_map<int, int> m;
        for (auto i : reservedSeats) {
            if (i[1] >= 2 && i[1] <= 9) {
                m[i[0]] |= (1 << (i[1] - 2));
                cout << m[i[0]] << "\n";
            }
        }
        int ans = 0;
        int l = 0b11110000, r = 0b00001111, mi = 0b00111100;
        for (auto i : m) {
            if (((i.second & l) == 0) && ((i.second & r) == 0)) {
                ans += 2;
            } else if (((i.second & l) == 0) || ((i.second & r) == 0) ||
                       ((i.second & mi) == 0)) {
                ans += 1;
            }
        }
        ans += (n - m.size())*2;
        return ans;
    }
};