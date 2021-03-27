#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  // count i < j < k, st nums[i] + nums[j] + nums[k] < target
  int threeSumSmaller(vector<int>& nums, int target)
  {
    int i, j, k, n, res, key;
    n = nums.size();
    res = 0;
    if (n < 3)
      return 0;

    sort(begin(nums), end(nums));

    for (i = 0; i < n - 2; ++i) {
      if (nums[i] + nums[i + 1] + nums[i + 2] >= target)
        break;
      j = i + 1;
      k = n - 1;
      while (j < k) {
        while (j < k && nums[i] + nums[j] + nums[k] >= target)
          --k;
        res += k - j;
        j++;
      }
    }
    return res;
  }
};
