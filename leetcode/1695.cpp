#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int maximumUniqueSubarray(vector<int>& nums)
  {
    int n, start, end, res, cur;
    unordered_set<int> seen;

    n = nums.size();

    for (cur = res = end = start = 0; end < n; ++end) {
      while (seen.find(nums[end]) != seen.end()) {
        cur -= nums[start];
        seen.erase(nums[start++]);
      }
      cur += nums[end];
      seen.insert(nums[end]);

      res = max(cur, res);
    }

    return res;
  }
};
