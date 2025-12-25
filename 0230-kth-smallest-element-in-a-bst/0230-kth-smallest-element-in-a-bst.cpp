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
    void find(TreeNode* root, int k, int &visited, int &ans){
        if(root == NULL) return;
        find(root->left, k, visited, ans);
        visited+=1;
        if(k==visited)
        ans=root->val;
        find(root->right, k, visited, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int visited = 0, ans=-1;
        find(root,k,visited,ans);
        return ans;
    }
};