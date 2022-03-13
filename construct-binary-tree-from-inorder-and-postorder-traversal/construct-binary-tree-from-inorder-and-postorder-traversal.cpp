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
    TreeNode* buildTreeHelp(vector<int>& inorder, vector<int>& postorder,int s1,int e1,int s2,int e2){
        if(s1==e1) return NULL;
        int val=postorder[e2-1];
        int leftEnd=s1;
        while(inorder[leftEnd]!=val) leftEnd+=1;
        TreeNode* root=new TreeNode(val);
        root->left=buildTreeHelp(inorder,postorder,s1,leftEnd,s2,s2+leftEnd-s1);
        root->right=buildTreeHelp(inorder,postorder,leftEnd+1,e1,s2+leftEnd-s1,e2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return NULL;
        int val=postorder[postorder.size()-1];
        int leftEnd=0;
        while(inorder[leftEnd]!=val) leftEnd+=1;
        TreeNode* root=new TreeNode(val);
        root->left=buildTreeHelp(inorder,postorder,0,leftEnd,0,leftEnd);
        root->right=buildTreeHelp(inorder,postorder,leftEnd+1,inorder.size(),leftEnd,inorder.size()-1);
        return root;
    }
};