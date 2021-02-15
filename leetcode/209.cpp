#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int l,r,res,n,sum;
      n = nums.size();
      res = numeric_limits<int>::max();
      l = r = 0;

      sum = nums[0];

      while (l < n && r < n) {
        if (sum >= target && r-l+1 < res) res = r-l+1;

        if (sum < target && r < n-1) {
          ++r;
          sum += nums[r];
        } else if (sum >= target && l < n-1) {
          sum -= nums[l];
          ++l;
        } else {
          break;
        }
      }
      return res != numeric_limits<int>::max() ? res : 0;
    }
};
