class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int n,i,sum,target;

      sum = 0;
      n = nums.size()-1;
      for (auto e: nums) sum+=e;

      if (sum % k != 0) return false;
      target = sum / k;

      sort(begin(nums), end(nums));

      while (n > 0 && nums[n] == target) {
        n--;
        k--;
      }

      vector<int> rems(k, target);

      return solve(nums, rems, k, n);
    }
private:
    bool solve(vector<int>& nums, vector<int>& res, int k, int n) {
      if (n < 0) return true;

      int v = nums[n--];

      
      for (int i = 0; i < k; ++i) {
        if (res[i] - v >= 0) {
          res[i] -= v;
          if (solve(nums, res, k, n)) return true;
          res[i] += v;
        }
        if (res[i] == 0) break;
      }
      return false;
    }
};
