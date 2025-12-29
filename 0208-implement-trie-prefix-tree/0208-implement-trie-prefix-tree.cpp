struct Node{
    Node* ch[26];
    bool isEnd=false;
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(auto i:word){
            if(node->ch[i-'a']==NULL){
                node->ch[i-'a']=new Node();
            }
            node = node->ch[i-'a'];
        }
        node->isEnd= true;
    }
    
    bool search(string word) {
         Node* node=root;
        for(auto i:word){
            if(node->ch[i-'a']==NULL){
                return false;
            }
            node = node->ch[i-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
         Node* node=root;
        for(auto i:prefix){
            if(node->ch[i-'a']==NULL){
                return false;
            }
            node = node->ch[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */