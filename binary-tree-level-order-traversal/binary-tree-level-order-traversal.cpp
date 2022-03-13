/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root!=NULL){
            queue<TreeNode *> q;
            q.push(root);
            vector<int> tmp;
            int len=q.size();
            while(!q.empty()){
                tmp.push_back(q.front()->val);
                len-=1;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
                if(len==0){
                    len=q.size();
                    ans.push_back(tmp);
                    tmp.erase(tmp.begin(),tmp.end());
                }
            }
        }
        return ans;
    }
};