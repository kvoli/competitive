#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
      
      int sum, n, i, j, target;
      sum = 0;

      n = nums.size();
      for (i = 0; i < n; ++i)  sum+=nums[i];
      if (sum % 2 == 1) return false; 
      target = sum / 2;
      
      vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));
      sort(nums.begin(), nums.end());


      for (i = 1; i <= n; ++i) dp[i][0] = true;
      for (j = 0; j <= target; ++j) dp[0][j] = false;


      for (i = 1; i <= n; ++i) {
        for (j = 1; j <= target; ++j) {
          if (nums[i-1] > j) dp[i][j] = dp[i-1][j];
          else {
            dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
          }
        }
      }
      return dp[n][target];
    }
};
