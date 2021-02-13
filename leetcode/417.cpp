#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& matrix,  vector<vector<int>>& visited, int i, int j, int n, int m) {

      visited[i][j] = 1;
      int cur = matrix[i][j];
      if (i < m-1 && !visited[i+1][j] && matrix[i+1][j] >= cur)
        dfs(matrix, visited, i+1, j, n, m);
      
      if (j < n-1 && !visited[i][j+1] && matrix[i][j+1] >= cur)
        dfs(matrix, visited, i, j+1, n, m);

      if (j > 0 && !visited[i][j-1] && matrix[i][j-1] >= cur)
        dfs(matrix, visited, i, j-1, n, m);

      if (i > 0 && !visited[i-1][j] && matrix[i-1][j] >= cur)
        dfs(matrix, visited, i-1, j, n, m);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

      int n,m,i,j;
      vector<vector<int>> ret;
      m = matrix.size();
      if (m == 0) return ret;
      n = matrix[0].size();
      if (n == 0) return ret;
      vector<vector<int>> pacificVisited(m, vector<int> (n, 0));
      vector<vector<int>> atlanticVisited(m, vector<int> (n, 0));

      for (i = 0; i < m; ++i) dfs(matrix, pacificVisited, i, 0, n, m);
      for (j = 0; j < n; ++j) dfs(matrix, pacificVisited, 0, j, n, m);
      for (j = 0; j < n; ++j) dfs(matrix, atlanticVisited, m-1, j, n, m);
      for (i = 0; i < m; ++i) dfs(matrix, atlanticVisited, i, n-1, n, m);


      for (i=0;i<m;++i){
        for(j=0;j<n;++j){
          if (pacificVisited[i][j] && atlanticVisited[i][j]) ret.push_back(vector<int> {i, j});
        }
      }

      return ret;
    }
};
