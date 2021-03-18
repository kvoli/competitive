#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int countSquares(vector<vector<int>>& matrix)
  {
    int i, j, n, m, res;

    n = matrix.size();
    m = matrix[0].size();
    res = 0;

    for (i = 0; i < n; ++i) {
      for (j = 0; j < m; ++j) {
        if (i > 0 && j > 0 && matrix[i][j] != 0)
          matrix[i][j] = min({ matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1] }) + 1;
        res += matrix[i][j];
      }
    }

    return res;
  }
};
