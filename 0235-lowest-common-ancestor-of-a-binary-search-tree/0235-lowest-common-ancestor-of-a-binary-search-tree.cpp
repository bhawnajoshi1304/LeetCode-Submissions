/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((p==NULL && q==NULL)||(root==NULL) )return NULL;
        TreeNode *left = lowestCommonAncestor(root->left,p,q), *right = lowestCommonAncestor(root->right,p,q);
        bool pFound=(left!=NULL && left==p)||(right!=NULL && right==p)||(root==p);
        bool qFound=(left!=NULL && left==q)||(right!=NULL && right==q)||(root==q);
        if(pFound && qFound) return root;
        if(pFound) return p;
        if(qFound) return q;
        if(left!=NULL) return left;
        if(right!=NULL) return right;
        return NULL;
    }
};