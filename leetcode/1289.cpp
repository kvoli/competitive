#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Solution {
  public:
  int minFallingPathSum(vector<vector<int>>& arr)
  {
    int n, tmp, i, j, k, res;
    pii prevMins;

    n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    // set the dp[0] row to just be the values of arr
    for (j = 0; j < n; ++j)
      dp[0][j] = arr[0][j];

    for (i = 1; i < n; ++i) {
      prevMins = getMin(dp, i - 1);
      cout << prevMins.first << " " << prevMins.second << endl;
      for (j = 0; j < n; ++j) {
        k = prevMins.first;
        if (j == prevMins.first)
          k = prevMins.second;
        dp[i][j] = dp[i - 1][k] + arr[i][j];
      }
    }
    res = INT_MAX;
    for (auto const& e : dp[n - 1])
      res = min(res, e);
    return res;
  }

  private:
  pii getMin(vector<vector<int>>& dp, int i)
  {
    if (dp.size() < 2)
      return { dp[i][0], dp[i][0] };
    int fst, snd, j;
    if (dp[i][0] > dp[i][1]) {
      fst = 1;
      snd = 0;
    } else {
      fst = 0;
      snd = 1;
    }
    for (j = 2; j < dp.size(); ++j) {
      if (dp[i][j] <= dp[i][fst]) {
        snd = fst;
        fst = j;
      } else if (dp[i][j] <= dp[i][snd]) {
        snd = j;
      }
    }
    return { fst, snd };
  }
};
