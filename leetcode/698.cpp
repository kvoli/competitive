#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& rems, int k, int n) {
      int i, v;
      if (n < 0) return true;

      v = nums[n];
      n--;
      for (i = 0; i < k; ++i) {
        if (rems[i] - v >= 0) {
          rems[i] -= v;
          if (solve(nums, rems, k, n)) return true;
          rems[i] += v;
        }
        if (rems[i] == 0) break;
      }

      return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int n, sum, target;

      n = nums.size();
      sum = 0;
      for (auto num : nums) sum += num;
      if (sum % k != 0) return false;
      target = sum / k;

      vector<int> rems(k, target);

      return solve(nums, rems, k, n - 1);
    }
};
