#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int minCost(vector<vector<int>>& costs)
  {
    int n, i, j, k, res, upper, lower;

    n = costs.size();
    k = 3;

    // dp array where each sub array [i,j,k] represents the min using that color last
    vector<vector<int>> dp(n, vector<int>(k, INT_MAX));

    for (j = 0; j < k; ++j)
      dp[0][j] = costs[0][j];

    for (i = 1; i < n; ++i) {
      for (j = 0; j < k; ++j) {

        if (j == 2)
          upper = dp[i - 1][0];
        else
          upper = dp[i - 1][j + 1];

        if (j == 0)
          lower = dp[i - 1][k - 1];
        else
          lower = dp[i - 1][j - 1];

        dp[i][j] = min(upper, lower) + costs[i][j];
      }
    }

    res = INT_MAX;

    for (j = 0; j < k; ++j)
      res = min(res, dp[n - 1][j]);

    return res;
  }
};
