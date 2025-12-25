
 struct Node {
    Node* ch[26];
    bool isEnd = false;
};
 class Trie {
    public:
    Node* root;
    Trie() : root(new Node()) {}
    void insert(string word) {
        Node* node = root;
        for (auto ch : word) {
            if (!node->ch[ch - 'a'])
                node->ch[ch - 'a'] = new Node();
            node = node->ch[ch - 'a'];
        }
        node->isEnd = true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        if (board.empty() || board[0].empty() || words.empty())
            return {};
        set<string> ans;
        Trie trie;
        for (auto w : words)
            trie.insert(w);
        string temp;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i+=1){
            for(int j=0;j<board[0].size();j+=1){
                Node* node = trie.root->ch[board[i][j]-'a'];
                if(node != NULL){
                    temp.clear();
                    temp.push_back(board[i][j]);
                    solve(i,j,node,ans,board,temp,visited);
                }
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
    void solve(int r, int c, Node* node,set<string> &ans, vector<vector<char>>& board, string &temp, vector<vector<bool>> &visited){
        if(node->isEnd){
            ans.insert(temp);
            node->isEnd = false; ////
        }
        visited[r][c]=true;
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto d: dirs){
            int nr=r+d[0],nc=c+d[1];
            if(!(nr<0 || nr>=board.size() || nc<0 || nc>=board[0].size()) && !visited[nr][nc]){
                Node *it = node->ch[board[nr][nc]-'a'];
                if(it!=NULL){
                    temp.push_back(board[nr][nc]);
                    solve(nr,nc,it,ans,board,temp,visited);
                    temp.pop_back();
                }
            }
        }
        visited[r][c]=false;
    }
};