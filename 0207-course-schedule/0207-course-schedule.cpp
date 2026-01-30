class Solution {
public:
    bool dfs(vector<vector<int>> &g, vector<int> &visited,int i){
        if(visited[i]==1) return true;
        if(visited[i]==2) return false;
        visited[i]=1;
        for(auto j:g[i]){
            if(visited[j]==1 || dfs(g,visited,j)) return true;
        }
        visited[i]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(auto i: prerequisites){
            g[i[1]].push_back(i[0]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i+=1){
            if(!visited[i]){
                if(dfs(g,visited,i)) return false;
            }
        }
        return true;
    }
};