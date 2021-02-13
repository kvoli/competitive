#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
      grid[i][j] = '0';
      if (i < m-1 && grid[i+1][j] == '1') dfs(grid, i+1, j, n, m);
      if (j < n-1 && grid[i][j+1] == '1') dfs(grid, i, j+1, n, m);
      if (i > 0 && grid[i-1][j] == '1') dfs(grid, i-1, j, n, m);
      if (j > 0 && grid[i][j-1] == '1') dfs(grid, i, j-1, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {

      int n,m,i,j,res;
      res = 0;
      m = grid.size();
      if (m == 0) return 0;
      n = grid[0].size();
      if (n == 0) return 0;

      for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
          if (grid[i][j] == '1') res++, dfs(grid, i, j, n, m);
        }
      }
      return res;
    }
};
