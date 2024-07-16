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
    vector<int>P;
    vector<pair<char,int>>Q;
    char state='N';
    void Traverse(vector<int>&pass1,vector<pair<char,int>>&pass2,TreeNode* root,int p,int q)
    {
        pass1.push_back(root->val);
        pass2.push_back({state,root->val});
        if(root->val==p)
        {
            P=pass1;
        }
        else if(root->val==q)
        {
            Q=pass2;
        }
        if(root->left!=NULL)
        {
            state='L';
            Traverse(pass1,pass2,root->left,p,q);
        }
        if(root->right!=NULL)
        {
            state='R';
            Traverse(pass1,pass2,root->right,p,q);
        }
        pass1.pop_back();
        pass2.pop_back();
        return;
    }
    vector<int> lowestCommonAncestor(TreeNode* root,int p,int q) 
    {
        vector<int>pass1;
        vector<pair<char,int>>pass2;
        Traverse(pass1,pass2,root,p,q);
        unordered_map<int,pair<int,int>>existsancestor;// exists index
        int spindex1,spindex2;
        for(int i=0;i<P.size();i++)
        {
            existsancestor[P[i]].first=true;
            existsancestor[P[i]].second=i;
        }
        for(int i=Q.size()-1;i>=0;i--)
        {
            if(existsancestor[Q[i].second].first==1)
            {
                spindex1=existsancestor[Q[i].second].second;
                spindex2=i;
                break;
            }
        }
        return {spindex1,spindex2};
    }
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        vector<int>index=lowestCommonAncestor(root,startValue,destValue);
        string ans;
        int i=P.size()-index[0];
        while(i--)
        {
            ans.push_back('U');
        }
        ans.pop_back();
        for(i=index[1]+1;i<Q.size();i++)
        {
            ans.push_back(Q[i].first);
        }
        return ans;
    }
};