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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        TreeNode *temp = NULL;
        while (root != NULL || !s.empty()){
            while (root != NULL){
                s.push(root);
                root = root->left;
            }
            while(root==NULL && !s.empty()){
                root=s.top();
                if(root->right==NULL || root->right==temp){
                    ans.push_back(root->val);
                    s.pop();
                    temp=root;
                    root=NULL;
                }else{
                    root=root->right;
                }
            }
        }
        return ans;
    }
};