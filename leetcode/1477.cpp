#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int minSumOfLengths(vector<int>& arr, int target)
  {
    int l, r, n, res, cumsum;

    n = arr.size();

    vector<int> dp(n, INT_MAX);

    res = INT_MAX;

    for (r = l = cumsum = 0; r < n; ++r) {
      cumsum += arr[r];
      while (cumsum > target) {
        cumsum -= arr[l++];
      }

      if (cumsum == target) {
        dp[r] = r - l + 1;
        if (l > 0 && dp[l - 1] != INT_MAX) {
          res = min(res, dp[r] + dp[l - 1]);
        }
      }
      if (r > 0) {
        dp[r] = min(dp[r - 1], dp[r]);
      }
    }
    return res != INT_MAX ? res : -1;
  }
};
