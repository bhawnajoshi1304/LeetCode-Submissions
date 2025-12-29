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
    int find(vector<int> &arr, int start, int size, int val){
        for(int i=start;i<start+size;i+=1){
            if(arr[i] == val) return i;
        }
        return -1;
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int lp, int size, int li) {
        if(size == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[lp]);
        int idx = find(inorder,li,size,root->val);
        root->left = buildTreeHelper(preorder,inorder,lp+1,idx-li,li);
        root->right = buildTreeHelper(preorder,inorder,lp+idx-li+1,size-(idx-li+1),idx+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder,inorder,0,preorder.size(),0);
        }
};