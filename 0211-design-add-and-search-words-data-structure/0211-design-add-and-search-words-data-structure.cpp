struct Node {
    Node* ch[26];
    bool isEnd;
    Node() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            ch[i] = NULL;
    }
};
class WordDictionary {
    Node* root;

public:
    WordDictionary() { root = new Node(); }
    bool search(Node* node, string word) {
        if (node == NULL && word.size() > 0)
            return false;
        if(word.size() == 0 && node!= NULL && node->isEnd) return true;
        for (int i = 0; i < word.size(); i += 1) {
            if (word[i] != '.') {
                if (node->ch[word[i] - 'a'] == NULL) {
                    return false;
                }
                node = node->ch[word[i] - 'a'];
            } else {
                bool found = false;
                for (int j = 0; j < 26; j += 1) {
                    if (node->ch[j] != NULL) {
                        found = found || search(node->ch[j],word.substr(i + 1, word.size() - i - 1));
                    }
                }
                return found;
            }
        }
        return node->isEnd == true;
    }
    void addWord(string word) {
        Node* node = root;
        for (auto i : word) {
            if (node->ch[i - 'a'] == NULL) {
                node->ch[i - 'a'] = new Node();
            }
            node = node->ch[i - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return search(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */