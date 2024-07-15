class Solution
{
    public:
        TreeNode* createBinaryTree(vector<vector < int>> &d)
        {
            unordered_set<int> s;
            for (int i = 0; i < d.size(); i++)//Finding all eligible candidates for root.
                s.insert(d[i][0]);

            for (int i = 0; i < d.size(); i++)//Eliminating all Un-eligible candidates.
                s.erase(d[i][1]);

            TreeNode *root = new TreeNode(*s.begin());
            unordered_map<int, pair<int, int>> m;

            for (int i = 0; i < d.size(); i++)//Creating map using values to find childrens in constant time(Since all values are unique).
            {
                if (m.find(d[i][0]) == m.end())
                    m[d[i][0]] = { i,-1 };
                else
                    m[d[i][0]].second = i;
            }
            queue<TreeNode*> q;//Performing BFS
            q.push(root);
            while (q.size())
            {
                int n = q.size();
                for (int i = 0; i < n; i++)
                {
                    TreeNode *x = q.front();
                    q.pop();
                    int a = -1, b = -1;
                    if (m.find(x->val) != m.end())
                    {
                        a = m[x->val].first;
                        b = m[x->val].second;
                    }
                    if (a != -1)
                        if (d[a][2] == 1) x->left = new TreeNode(d[a][1]);
                        else x->right = new TreeNode(d[a][1]);
                    if (b != -1)
                        if (d[b][2] == 1) x->left = new TreeNode(d[b][1]);
                        else x->right = new TreeNode(d[b][1]);
                    if (x->left) q.push(x->left);
                    if (x->right) q.push(x->right);
                }
            }
            return root;
        }
};