#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int r, c, i, j;

      r = matrix.size();
      c = matrix[0].size();

      vector<bool> rz (r, false);
      vector<bool> cz (c, false);

      for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
          if (matrix[i][j] == 0) {
            rz[i] = true;
            cz[j] = true;
          }
        }
      }
        
        

      for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
          if (rz[i] || cz[j])  matrix[i][j] = 0;
        }
      }
    }
};

