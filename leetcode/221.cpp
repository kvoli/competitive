class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int n,m,i,j,res,a,b,c;
      n = matrix.size();
      m = matrix[0].size();
      res = 0;
      vector<vector<int>> dp(n, vector<int>(m, 0));

      for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
          if (matrix[i][j] - '0' ==  1)  {
            a = i > 0 ? dp[i-1][j] : 0;
            b = j > 0 ? dp[i][j-1] : 0;
            c = j > 0 && i > 0 ? dp[i-1][j-1] : 0;
            dp[i][j] = min({a,b,c}) + 1;
            res = max(res, dp[i][j]);
          }
        }
      }

      return res*res;
    }
};
