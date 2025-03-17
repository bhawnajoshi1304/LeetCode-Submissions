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
    int dist(TreeNode *root,int &diameter){
        if(root==NULL)
            return 0;
        int dl=dist(root->left,diameter),dr=dist(root->right,diameter);
        diameter=max(diameter,dl+dr);
        return 1+max(dl,dr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter=0;
        dist(root,diameter);
        return diameter;
    }
};