class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int odd, res, end, n, start;
      odd = res = start = 0;
      n = nums.size();
      for (end = 0; end < n; ++end) {
        while (odd == k) {
          res++;
          if (nums[start++] % 2 == 1) --odd;
        }
        if (nums[end] % 2 == 1) ++odd;
      }
      return res;
    }
};
