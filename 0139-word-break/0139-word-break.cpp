
class Node {
public:
    Node* ch[26];
    bool isEnd;
};
class Trie {
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(string s) {
        Node* tmp = root;
        for (auto i : s) {
            if (tmp->ch[i - 'a'] == nullptr)
                tmp->ch[i - 'a'] = new Node();
            tmp = tmp->ch[i - 'a'];
        }
        tmp->isEnd = true;
    }

    bool find(string s) {
        Node* tmp = root;
        for (auto i : s) {
            if (tmp->ch[i - 'a'] == nullptr)
                return false;
            tmp = tmp->ch[i - 'a'];
        }
        return tmp->isEnd;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* t = new Trie();
        for (auto i : wordDict)
            t->insert(i);
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
        dp[n][0] = true;
        for (int i = 0; i < n; i += 1) {
            dp[i][0] = true;
            for (int j = i + 1; j <= n; j += 1) {
                dp[i][j] = t->find(s.substr(i, j - i));
                dp[n][j] = (dp[n][i] && dp[i][j]) || dp[n][j];
            }
        }
        return dp[n][n];
    }
};