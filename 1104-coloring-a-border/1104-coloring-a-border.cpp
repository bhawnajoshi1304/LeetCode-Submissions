class Solution {
public:
vector<vector<bool>>visited;
  bool dfs(vector<vector<int>>& grid, int r, int c, int original_color,int border_color){
    int m=grid.size(),n=grid[0].size();
    if(r<0 || c<0 || r>=m || c>=n ) return true;
    if(visited[r][c]==true) return false;
    if(grid[r][c]!=original_color) return true;
    visited[r][c]=true;//marked as visited
    int x=0;
    x+=dfs(grid,r+1,c,original_color,border_color); 
    x+=dfs(grid,r-1,c,original_color,border_color); 
    x+=dfs(grid,r,c+1,original_color,border_color);
    x+=dfs(grid,r,c-1,original_color,border_color);
   if(x>0) grid[r][c]=border_color;
    return false;
  }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        visited.resize(grid.size(),vector<bool>(grid[0].size(),false));
        dfs(grid,row,col,grid[row][col],color);
        return grid;
    }
};