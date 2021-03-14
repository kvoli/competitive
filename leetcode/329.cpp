#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int longestIncreasingPath(vector<vector<int>>& matrix)
  {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        solve(matrix, i, j, -1, dp);
      }
    }
    return res;
  }

  private:
  int res;
  int solve(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>>& dp)
  {
    if (i < 0 || i > matrix.size() - 1 || j < 0 || j > matrix[0].size() - 1 || matrix[i][j] <= prev)
      return 0;
    if (dp[i][j] > 1)
      return dp[i][j];

    int ret = max({
                  solve(matrix, i + 1, j, matrix[i][j], dp),
                  solve(matrix, i - 1, j, matrix[i][j], dp),
                  solve(matrix, i, j + 1, matrix[i][j], dp),
                  solve(matrix, i, j - 1, matrix[i][j], dp),
              })
        + 1;

    dp[i][j] = max(dp[i][j], ret);
    res = max(res, dp[i][j]);

    return ret;
  }
};
