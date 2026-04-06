class Solution {
public:
    static int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>> mx, my;
        mx.reserve(10000), my.reserve(10000);
        for (auto& ob : obstacles) {
            int x = ob[0], y = ob[1];
            mx[x].insert(y);
            my[y].insert(x);
        }
        //                   north   west     south    east
        const int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int x = 0, y = 0, dx = 0, dy = 1, dir = 0, ans = 0;
        for (int c : commands) {
            switch (c) {
            case -2:
                dir = (dir + 1) % 4;
                dx = d[dir][0];
                dy = d[dir][1];
                break;
            case -1:
                dir = (dir + 3) % 4;
                dx = d[dir][0];
                dy = d[dir][1];
                break;
            default:
                bool isYaxis = (dir % 2 == 0); // north or south
                auto& axis = isYaxis ? mx[x] : my[y];
                int& pos = isYaxis ? y : x;
                bool inc = (dir == 0 || dir == 3); // north or east
                if (inc) {
                    auto it = axis.upper_bound(pos);
                    if (it != axis.end() && *it <= pos + c)
                        pos = *it - 1;
                    else
                        pos += c;
                } else {
                    auto it = axis.lower_bound(pos);
                    if (it != axis.begin() && *(--it) >= pos - c)
                        pos = *it + 1;
                    else
                        pos -= c;
                }
                ans = max(ans, x * x + y * y);
                break;
            }
        }
        return ans;
    }
};