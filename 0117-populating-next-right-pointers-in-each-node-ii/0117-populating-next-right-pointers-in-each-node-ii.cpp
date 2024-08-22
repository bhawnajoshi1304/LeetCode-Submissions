/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // Level order traversal 
        if(root==NULL) return root;
        queue<Node*> q;
        int pLevel=1,cLevel=0;
        q.push(root);
        while(!q.empty()){
            Node *tmp = q.front();
            q.pop();
            pLevel-=1;
            if(tmp->left) {cLevel+=1;q.push(tmp->left);}
            if(tmp->right) {cLevel+=1;q.push(tmp->right);}
            if(pLevel && !q.empty()) {
                tmp->next = q.front();
            }
            else{
                pLevel=cLevel;
                cLevel=0;
            }
        }
        return root;
    }
};