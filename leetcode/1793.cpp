class Solution {
  public:
  int maximumScore(vector<int>& nums, int k)
  {
    int i, j, mn, res, lmin, rmin, n;

    i = j = k;
    res = mn = nums[k];
    n = nums.size();

    while (i >= 0 && j <= n - 1) {
      lmin = min(mn, i > 0 ? nums[i - 1] : 0);
      rmin = min(mn, j < n - 1 ? nums[j + 1] : 0);

      if (lmin >= rmin)
        --i;
      else
        ++j;

      mn = max(lmin, rmin);
      res = max(res, mn * (j - i + 1));
    }
    return res;
  }
};
