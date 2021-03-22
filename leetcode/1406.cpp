#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  string stoneGameIII(vector<int>& stoneValue)
  {
    vector<int> dp(4);
    int i, k, take, n;
    n = stoneValue.size();
    for (i = n - 1; i >= 0; --i) {
      dp[i % 4] = -2000;
      for (k = take = 0; k < 3 && i + k < n; ++k) {
        dp[i % 4] = max(dp[i % 4], (take += stoneValue[i + k]) - dp[(i + k + 1) % 4]);
      }
    }
    return dp[0] == 0 ? "Tie" : dp[0] > 0 ? "Alice"
                                          : "Bob";
  }
};
