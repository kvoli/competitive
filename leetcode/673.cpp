#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

      int i, j, n, res, eq;


      n = nums.size();
      res = 0;
      eq = 0;

      vector<int> dp(n, 0);
      vector<int> cnt(n, 1);
      for (i = 0; i < n; ++i) {
        for (j = 0; j < i; ++j){
          if (nums[j] < nums[i]) {

            if (dp[j] >= dp[i]) {
              cnt[i] = cnt[j];
              dp[i] = dp[j] + 1;
            } else if (dp[j] == dp[i]-1) {
              cnt[i] += cnt[j];
            }
          }
        }
      }
      
      int longest, ans;
      longest = ans = 0;
      for (auto e: dp) longest = longest > e ? longest : e;

      for (i = 0; i < n; ++i) {
        if (dp[i] == longest) {
          eq += cnt[i];
        }
      }
      return eq; 
    }
};
