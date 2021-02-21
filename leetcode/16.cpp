class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int i,j,k,res,cur,n;
      n = nums.size();
      if (n < 3) return 0;
      sort(begin(nums), end(nums));
      closest = nums[0] + nums[1] + nums[2];
      for (i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        j = i+1;
        k = n-1;
        while (j < k) {
          cur = nums[i] + nums[j] + nums[k];
          if (cur == target) return cur;
          if (abs(target - cur) < abs(target - res)) res = cur;
          if (cur > target) --k;
          if (cur < target) ++j;
        }
      }
      return res;
    }
};
