class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, freq] : m) {
            pq.push({freq, ch});
        }
        string ans;
        while (pq.size() >= 2) {
            auto [c1, a] = pq.top();
            pq.pop();
            auto [c2, b] = pq.top();
            pq.pop();
            ans += a;
            ans += b;
            if (--c1 > 0)
                pq.push({c1, a});
            if (--c2 > 0)
                pq.push({c2, b});
        }
        if (!pq.empty()) {
            auto [freq, ch] = pq.top();
            if (freq > 1)
                return "";
            ans += ch;
        }
        return ans;
    }
};
/*
class Solution {
public:
    string reorganizeString(string s) {
    unordered_map<char, int> m;
    for (char c : s) {
        m[c]++;
    }

    vector<char> sorted_chars;
    for (auto& pair : m) {
        sorted_chars.push_back(pair.first);
    }

    sort(sorted_chars.begin(), sorted_chars.end(), [&](char a, char b) {
        return m[a] > m[b];
    });

    if (m[sorted_chars[0]] > (s.length() + 1) / 2) {
        return "";
    }

    string res(s.length(), ' ');
    int i = 0;
    for (char c : sorted_chars) {
        for (int j = 0; j < m[c]; ++j) {
            if (i >= s.length()) {
                i = 1;
            }
            res[i] = c;
            i += 2;
        }
    }

    return res;
}
};

*/