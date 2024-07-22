class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> pair;
        for (int i = 0; i < names.size(); i++) {
            pair.push_back({heights[i], names[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<string> res;
        for (const auto& person : pair) {
            res.push_back(person.second);
        }
        return res;
    }
};
