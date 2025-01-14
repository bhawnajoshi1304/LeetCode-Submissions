class Solution {
public:
void dfs(int x, vector<vector<int>> &adj, vector<bool> &visited){
    visited[x]=true;
    cout<<x<<" ";
    for(auto i: adj[x]){
        if(!visited[i])
            dfs(i,adj,visited);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i+=1){
            for(int j=0;j<n;j+=1){
                if(i!=j && isConnected[i][j])
                adj[i].push_back(j);
            }
        }
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i+=1){
            if(!visited[i]){
                ans+=1;
                dfs(i,adj,visited);
                cout<<"\n";
            }
        }
        return ans;
    }
};