class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<string> board(n, string(n, '.'));
      vector<vector<string>> res;
      solve(res, board, 0, n);
      return res;
        
    }
private:
    void solve(vector<vector<string>> &res, vector<string> &cur, int row, int &n) {
      if (row == n) {
        res.push_back(cur);
        return;
      }

      for (int col = 0; col < n; ++col) {
        if (check(cur, row, col, n)) {
          cur[row][col] = 'Q';
          solve(res, cur, row+1, n);
          cur[row][col] = '.';
        }
      }
    }

    bool check(vector<string> &cur, int row, int col, int &n) {
      int i, j;
      for (i = 0; i != row; ++i) if (cur[i][col] == 'Q') return false;
      for (i = row-1, j = col - 1; i >= 0 && j >=0; --i, --j) if (cur[i][j] == 'Q') return false;
      for (i = row-1, j = col + 1; i >= 0 && j < n; --i, ++j) if (cur[i][j] == 'Q') return false;
      return true;
    }
};
