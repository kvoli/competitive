#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ways = 0;
    void solve(vector<int>& nums, long long target, int start, int n){
      if (start == n && target != 0) return;
      if (start == n && target == 0) {
        ways++;
        return;
      }
      solve(nums, target - nums[start], start+1, n);
      solve(nums, target + nums[start], start+1, n);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
      int n = nums.size();
      long long target = S;
      solve(nums, target, 0, n);
      return ways;
    }
};
