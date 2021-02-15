class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int n,m,i,j;
      m = matrix.size();
      n = matrix[0].size();

      i = m-1;
      j = 0;

      while (i >= 0 && j < n) {
        if (target == matrix[i][j]) return true;
        if (target > matrix[i][j]) j++;
        if (target < matrix[i][j]) i--;
      }

      return false;
    }
};
