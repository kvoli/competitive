class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int start,end,n,res,cur;

      n = nums.size();
      start = res = 0;
      cur = 1;
      if (k <= 1) return 0;

      for (end = 0; end < n; ++end) {
        cur *= nums[end];
        while (cur >= k) cur /= nums[start++];
        res += end - start + 1;
      }
      return res;
    }
};
