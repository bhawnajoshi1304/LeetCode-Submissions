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
    bool checkMirror(TreeNode* t1,TreeNode* t2){
        if((t1==NULL)^(t2==NULL)) return false;
        if(t1==NULL && t2==NULL) return true;
        return ((t1->val==t2->val )&&checkMirror(t1->left,t2->right)&&checkMirror(t1->right,t2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if((root->left==NULL)^(root->right==NULL)) return false;
        if(root->left==NULL && root->right==NULL) return true;
        return ((root->right->val==root->left->val )&&checkMirror(root->left,root->right));
    }
};