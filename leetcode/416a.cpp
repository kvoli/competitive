class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int n,i,j,sum,target;
      n = nums.size();

      sum = 0;
      for (auto n:nums)sum+=n;
      target = sum / 2;

      if (sum % 2 != 0) return false;

      sort(begin(nums), end(nums));
      vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));


      for (i = 0; i <= target; ++i) dp[0][i] = false;
      for (i = 1; i <= n; ++i) dp[i][0] = true;

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
