class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int i,n,j,tmp;
      n = matrix.size();
      for (i=0;i<(n+1)/2;++i){
        for (j=0;j<n/2;++j) {
          tmp = matrix[n-1-j][i];
          matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
          matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
          matrix[j][n-1-i] = matrix[i][j];
          matrix[i][j] = tmp;
        }
      }
    }
};
