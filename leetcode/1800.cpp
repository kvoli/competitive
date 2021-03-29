class Solution {
  public:
  int maxAscendingSum(vector<int>& nums)
  {
    int i, start, n, res, cur;

    n = nums.size();
    cur = res = nums[0];
    for (i = 1; i < n; ++i) {
      if (nums[i] <= nums[i - 1])
        cur = 0;
      cur += nums[i];
      res = max(cur, res);
    }

    return res;
  }
};
