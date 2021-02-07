#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int i, j, n, res;
      res = 0;
      n = nums.size();
      vector<int> dp(n, 1);

      for (i = 0; i < n; ++i) {
        for (j = 0; j < i; ++j) {
          if (nums[j] < nums[i] && dp[j] >= dp[i]) dp[i] = dp[j] + 1;
        }
        res = res > dp[i] ? res : dp[i];
      }
    return res;
  }
};
