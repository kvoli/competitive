#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int> dp(amount+1, 999999999);
      sort(coins.begin(), coins.end());
      dp[0] = 0;

      for (int i = 1; i <= amount; ++i) {
        for (auto c: coins) {
          if (c <= i) dp[i] = dp[i] > dp[i-c] + 1 ? dp[i-c] + 1 : dp[i];
        }
      }
      return dp[amount] <  999999999 ? dp[amount] : -1;
    }
};
