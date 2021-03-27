#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int numberOfSubarrays(vector<int>& nums, int k)
  {
    int n, i, j, odds, count, res;

    n = nums.size();
    j = odds = count = res = 0;

    for (i = 0; i < n; ++i) {
      if (nums[i] & 1) {
        odds++;
        if (odds >= k) {
          count = 1;
          while (!(nums[j++] & 1))
            count++;
          res += count;
        }
      } else if (odds >= k)
        res += count;
    }
    return res;
  }
};
