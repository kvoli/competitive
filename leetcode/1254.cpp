#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int closedIsland(vector<vector<int>>& grid)
  {

    int islands, i, j, n, m;
    islands = 0;

    n = grid.size();
    m = grid[0].size();

    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        if (grid[i][j] == 0 && solve(grid, n, m, i, j))
          islands++;
      }
    }
    return islands;
  }

  private:
  bool solve(vector<vector<int>>& grid, int n, int m, int i, int j)
  {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1)
      return false;
    if (grid[i][j] == 1)
      return true;
    if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
      grid[i][j] = -1;
      return false;
    }

    grid[i][j] = 1;
    bool ret = solve(grid, n, m, i + 1, j)
        && solve(grid, n, m, i - 1, j)
        && solve(grid, n, m, i, j + 1)
        && solve(grid, n, m, i, j - 1);
    if (!ret) {
      grid[i][j] = -1;
    }
    return ret;
  }
};

//[ [0,0,1,1,0,1,0,0,1,0],
//[1,1,0,1,1,0,1,1,1,0],
//[1,0,1,1,1,0,0,1,1,0],
//[0,1,1,0,0,0,0,1,0,1],
//[0,0,0,0,0,0,1,1,1,0],
//[0,1,0,1,0,1,0,1,1,1],
//[1,0,1,0,1,1,0,0,0,1],
//[1,1,1,1,1,1,0,0,0,0],
//[1,1,1,0,0,1,0,1,0,1],
//[1,1,1,0,1,1,0,1,1,0]
//]
//
//
//0, 0, 1, 1, 0, 1, 0, 0, 1, 0,
//1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
//1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//1, 1, 1, 0, 1, 1, 0, 1, 1, 0,
