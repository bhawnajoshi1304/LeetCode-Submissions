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
    static void postOrder(TreeNode* root, int &count, int &n,int &sum){
        if(root == nullptr) return;
        postOrder(root->left,count,n,sum);
        int tmpN=0,tmpSum=0;
        postOrder(root->right,count,tmpN,tmpSum);
        n+=1+tmpN;
        sum+=root->val+tmpSum;
        cout<<root->val<<n<<sum<<"\n";
        count+=(root->val == (sum/n));
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0,n=0,sum=0;
        postOrder(root,count,n,sum);
        return count;
    }
};