class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int i,j,n,m,res;
      n = grid.size();
      m = grid[0].size();
      res = 0;
      for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
          res = max(res, dfs(grid, i, j, n, m));
        }
      }
      return res;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
      if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) return 0;

      grid[i][j] = 0;
      return 1 + dfs(grid, i+1, j, n, m) +
        dfs(grid, i-1, j, n, m) + 
        dfs(grid, i, j+1, n, m) +
        dfs(grid, i, j-1, n, m) 
    }
};
