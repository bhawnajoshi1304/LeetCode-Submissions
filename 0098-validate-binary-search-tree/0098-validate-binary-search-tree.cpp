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
 #include<bits/stdc++.h>
 using namespace std;
class Solution {
public:
    int min(long a,int b){
        return (a<b)?a:b;
    }
    int max(long a, int b){ return (a>b)?a:b;}
    bool isValidBST(TreeNode* root,long low = LONG_MIN, long high = LONG_MAX) {
        if(root == NULL) return true;
        if( root->val <=low || root->val >= high) return false;
        return isValidBST(root->left,low,min(high,root->val)) && isValidBST(root->right,max(low,root->val),high);
    }
};