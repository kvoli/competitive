#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

      vector<int> res;

      if (matrix.size() < 1) return res;

      int r1, r2, c1, c2, r, c;
  
      r1 = c1 = 0;
      r2 = matrix.size() - 1;
      c2 = matrix[0].size() - 1;

      while (r1 <= r2 && c1 <= c2) {
        for (c = c1; c <= c2; ++c) res.push_back(matrix[r1][c]);
        for (r = r1 + 1; r <= r2; ++r) res.push_back(matrix[r][c2]);
        if (r1 < r2 && c1 < c2) {
          for (c = c2 - 1; c > c1; --c) res.push_back(matrix[r2][c]);
          for (r = r2; r > r1; --r) res.push_back(matrix[r][c1]);
        }
        r1++;
        r2--;
        c1++;
        c2--;
      }
      return res;
    }

};
