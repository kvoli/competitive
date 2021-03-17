#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  string minWindow(string S, string T)
  {
    int k, i, j, n, m, start, best;
    n = S.size();
    m = T.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (i = 0; i < n; ++i)
      dp[0][i] = S[i] == T[0] ? i : -1;

    for (j = 1; j < m; ++j) {
      k = -1;
      for (i = 0; i < n; ++i) {
        if (k != -1 && S[i] == T[j])
          dp[i][j] = k;
        if (dp[j - 1][i] != -1)
          k = dp[j - 1][i];
      }
    }

    best = INT_MAX;
    start = -1;
    for (i = 0; i < n; ++i) {
      if (dp[m - 1][i] != -1 && i - dp[m - 1][i] + 1 < best) {
        start = dp[m - 1][i];
        best = i - dp[m - 1][i] + 1;
      }
    }

    return start == -1 ? "" : S.substr(start, best);
  }
};
