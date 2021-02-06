#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    int m;
    int n;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
      if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) return false;
      if (k == word.length() - 1) return true;

      char cur = board[i][j];
      board[i][j] = '*';
      bool res = dfs(board, word, i + 1, j, k + 1) || 
                 dfs(board, word, i - 1, j, k + 1) ||
                 dfs(board, word, i, j + 1, k + 1) ||
                 dfs(board, word, i, j - 1, k + 1);
      board[i][j] = cur;
      return res;
    }

  public:

    bool exist(vector<vector<char>>& board, string word) {
      int i, j;
      m = board.size();
      n = board[0].size();

      set<pair<int, int>> seen;
      
      for (i = 0; i < m; ++i){
        for (j = 0; j < n; ++j){
          if (dfs(board, word, i, j, 0)) return true;
        }
      }
      return false;
    }
};
